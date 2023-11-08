#include <iostream>
#include <cmath>

using namespace std;

int dp[101][101];

void draw() {
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (dp[i][j] && dp[i + 1][j]) dp[i + 1][j] = dp[i][j] + 1;
		}
	}
}

int solve(int row, int col) {
	int h = 100, ret = 0;
	for (int i = col; i <= 100; i++) {
		if (!dp[row][i]) return ret;

		h = min(h, dp[row][i]);
		ret = max(ret, h * (i - col + 1));
	}
	
	return ret;
}

int main() { //»öÁ¾ÀÌ - 3
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int r, c;
		cin >> c >> r;

		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) dp[r + j][c + k] = 1;
		}
	}
	draw();

	int res = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (dp[i][j]) res = max(res, solve(i, j));
		}
	}

	cout << res;
}