#include <iostream>

using namespace std;
typedef long long ll;

int N, arr[100][100];
ll dp[100][100];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> arr[i][j];
	}
	dp[N - 1][N - 1] = 1;
}

bool checkRowCol(int row, int col) {
	if (row >= N || col >= N) return false;
	return true;
}

ll recur(int row, int col) {
	if (dp[row][col] || !arr[row][col]) return dp[row][col];

	if (checkRowCol(row + arr[row][col], col)) dp[row][col] += recur(row + arr[row][col], col);
	if (checkRowCol(row, col + arr[row][col])) dp[row][col] += recur(row, col + arr[row][col]);

	return dp[row][col];
}

void solve() {
	recur(0, 0);
	cout << dp[0][0];
}

int main() { //มกวม
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}