#include <iostream>
#include <cmath>

using namespace std;
void recur(int, int);

int N, M, door[21], open[2], res;

void input() {
	cin >> N;
	for (int i = 0; i < 2; i++) cin >> open[i];
	
	cin >> M;
	for (int i = 0; i < M; i++) cin >> door[i];

	res = 1e9;
}

void changeDoor(int index, int cnt, int temp) {
	int o = open[index];
	open[index] = door[cnt];
	recur(cnt + 1, temp + abs(o - door[cnt]));
	open[index] = o;
}

void recur(int cnt, int temp) {
	if (cnt == M) {
		res = min(temp, res);
		return;
	}

	changeDoor(0, cnt, temp);
	changeDoor(1, cnt, temp);
}

void solve() {
	recur(0, 0);
	cout << res;
}

int main() { //벽장문의 이동
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}