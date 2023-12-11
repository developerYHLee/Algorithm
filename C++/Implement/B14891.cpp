#include <iostream>
#include <memory.h>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;

int gear[5][8], act[100][2], K, vis[5];

void input() {
	for (int i = 1; i <= 4; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < 8; j++) gear[i][j] = str[j] - '0';
	}

	cin >> K;

	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;

		act[i][0] = a;
		act[i][1] = b;
	}
}

void move(int num) {
	int prev = gear[num][0];
	for (int i = 1; i < 8; i++) {
		int temp = gear[num][i];
		gear[num][i] = prev;
		prev = temp;
	}
	gear[num][0] = prev;
}

void move_reverse(int num) {
	int prev = gear[num][7];
	for (int i = 6; i >= 0; i--) {
		int temp = gear[num][i];
		gear[num][i] = prev;
		prev = temp;
	}
	gear[num][7] = prev;
}

void rot() {
	for (int i = 1; i <= 4; i++) {
		if (vis[i] == 1) move(i);
		else if (vis[i] == -1) move_reverse(i);
	}
}

void comp(int num, int dir, bool fromRight) {
	vis[num] = dir;

	if (num == 1) {
		if (!fromRight && gear[1][2] != gear[2][6]) comp(2, -dir, false);
	}
	else if (num == 2) {
		if (fromRight && gear[2][6] != gear[1][2]) comp(1, -dir, true);
		if (!fromRight && gear[2][2] != gear[3][6]) comp(3, -dir, false);
	}
	else if (num == 3) {
		if (fromRight && gear[3][6] != gear[2][2]) comp(2, -dir, true);
		if (!fromRight && gear[3][2] != gear[4][6]) comp(4, -dir, false);
	}
	else if (num == 4) {
		if (fromRight && gear[4][6] != gear[3][2]) comp(3, -dir, true);
	}
}

int answer() {
	int ret = 0;

	for (int i = 1; i <= 4; i++) {
		if (gear[i][0]) ret += (int)pow(2, i - 1);
	}

	return ret;
}

void solve() {
	for (int i = 0; i < K; i++) {
		memset(vis, 0, sizeof(vis));
		comp(act[i][0], act[i][1], false);
		comp(act[i][0], act[i][1], true);
		rot();
	}
}

int main() { //Åé´Ï¹ÙÄû
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
	cout << answer();
}