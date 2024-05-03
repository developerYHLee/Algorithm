#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 1e6;
int N, M, cost[1000][1000], dp[1000][1000][3], dx[3] = { -1, 0, 1 };

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> cost[i][j];

			for(int k = 0; k < 3; k++) dp[i][j][k] = MAX;
		}
	}
}

int getMinCost(int row, int col, int dir) {
	int ret = MAX;

	for (int i = 0; i < 3; i++) {
		if (i == dir) continue;
		ret = min(ret, dp[row][col][i]);
	}

	return ret;
}

void setDp() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < 3; j++) dp[0][i][j] = cost[0][i];
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 3; k++) {
				int prevR = i - 1;
				int prevC = j + dx[k];

				if (prevC < 0 || prevC >= M) continue;

				int minCost = getMinCost(prevR, prevC, k);
				dp[i][j][k] = min(dp[i][j][k], minCost + cost[i][j]);
			}
		}
	}
}

void solve() {
	setDp();

	int res = MAX;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < 3; j++) res = min(res, dp[N - 1][i][j]);
	}

	cout << res;
}

int main() { //진우의 달 여행 (Large)
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}