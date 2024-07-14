#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

struct Room {
	int type, att, hp;
};

int N;
ll curAtt, curHp, maxHp;
Room room[123'456];

void input() {
	cin >> N >> curAtt;

	for (int i = 0; i < N; i++) {
		cin >> room[i].type >> room[i].att >> room[i].hp;
		
		if (room[i].type == 2) curAtt += room[i].att;
	}
}

ll getDamage(int index) { return (room[index].hp - 1) / curAtt * room[index].att; }

void enterRoom(ll& hasToRemainHp, int index) {
	if (room[index].type == 1) {
		hasToRemainHp += getDamage(index);
		maxHp = max(maxHp, hasToRemainHp);
	}
	else {
		curAtt -= room[index].att;
		hasToRemainHp = max((ll)1, hasToRemainHp - room[index].hp);
	}
}

void solve() {
	ll hasToRemainHp = getDamage(N - 1) + 1;
	maxHp = hasToRemainHp;

	for (int i = N - 2; i >= 0; i--) enterRoom(hasToRemainHp, i);

	cout << maxHp;
}

int main() { //µå·¡°ï ¾Ø ´øÀü
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}