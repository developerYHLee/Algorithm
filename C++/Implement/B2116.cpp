#include <iostream>
#include <cmath>

using namespace std;

int N, dice[10000][6], res, temp;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 6; j++) cin >> dice[i][j];
	}
}

void checkNum(int n1, int n2) {
	if (n1 == 6 || n2 == 6) {
		if (n1 == 5 || n2 == 5) temp += 4;
		else temp += 5;
	}
	else temp += 6;
}

int checkDice(int k, int index) {
	if (index == 0 || index == 5) {
		checkNum(dice[k][0], dice[k][5]);
		return index == 0 ? 5 : 0;
	}
	else if (index == 1 || index == 3) {
		checkNum(dice[k][1], dice[k][3]);
		return index == 1 ? 3 : 1;
	}
	else {
		checkNum(dice[k][2], dice[k][4]);
		return index == 2 ? 4 : 2;
	}
}

void recur(int k, int nextNum) {
	if (k == N) return;

	for (int i = 0; i < 6; i++) {
		if (dice[k][i] == nextNum) {
			recur(k + 1, dice[k][checkDice(k, i)]);
			return;
		}
	}
}

void solve() {
	for (int i = 0; i < 6; i++) {
		temp = 0;
		recur(1, dice[0][checkDice(0, i)]);
		res = max(res, temp);
	}

	cout << res;
}

int main() { //ÁÖ»çÀ§ ½×±â
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}