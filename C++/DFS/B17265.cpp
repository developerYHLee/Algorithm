#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

void recur(int, int, int);

int N, minDp[5][5], maxDp[5][5], dx[3] = { 1, 0, 1 }, dy[3] = { 0, 1, 1 };
char arr[5][5];

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			minDp[i][j] = INT_MAX;
			maxDp[i][j] = INT_MIN;
		}
	}
	
	maxDp[0][0] = arr[0][0] - '0';
	minDp[0][0] = arr[0][0] - '0';
}

int calValue(char o, int v1, int v2) {
	switch (o)
	{
	case '+': 
		return v1 + v2;
	case '-':
		return v1 - v2;
	case '*':
		return v1 * v2;
	}

	return -1;
}

void checkRowCol(int o_r, int o_c, int n_r, int n_c, int v) {
	if (o_r < 0 || o_c < 0 || o_r >= N || o_c >= N) return;

	char o = arr[o_r][o_c];
	int nextV = calValue(o, v, arr[n_r][n_c] - '0');

	if (nextV > maxDp[n_r][n_c]) {
		maxDp[n_r][n_c] = nextV;
		recur(n_r, n_c, nextV);
	}
	if (nextV < minDp[n_r][n_c]) {
		minDp[n_r][n_c] = nextV;
		recur(n_r, n_c, nextV);
	}
}

void recur(int row, int col, int v) {
	for (int i = 0; i < 2; i++) {
		int o_r = row + dx[i];
		int o_c = col + dy[i];
		int n_r = row + dx[i] * 2;
		int n_c = col + dy[i] * 2;

		checkRowCol(o_r, o_c, n_r, n_c, v);
	}

	int n_r = row + dx[2];
	int n_c = col + dy[2];

	for (int i = 0; i < 2; i++) {
		int o_r = row + dx[i];
		int o_c = col + dy[i];

		checkRowCol(o_r, o_c, n_r, n_c, v);
	}
}

void solve() {
	recur(0, 0, arr[0][0] - '0');
	cout << maxDp[N - 1][N - 1] << " " << minDp[N - 1][N - 1];
}

int main() { //나의 인생에는 수학과 함께
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}