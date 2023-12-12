#include <iostream>
#include <cmath>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 1 << 16;
int cost[16][16], dp[16][16][MAX];
int res, N;

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;

		for (int j = 1; j <= N; j++) cost[i][j] = str[j - 1] - '0';
	}

	fill_n(&dp[0][0][0], 16 * 16 * MAX, 1e9);
	dp[1][1][2] = 0;
}

void make_dp() {
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (j == k) continue;

				for (int l = 2; l < MAX; l++) {
					if (l & (1 << k)) continue;

					int bit = l | (1 << k);

					if (cost[j][k] >= dp[i][j][l]) dp[i + 1][k][bit] = min(dp[i + 1][k][bit], cost[j][k]);
				}
			}
		}
	}
}

int solve() {
	make_dp();

	for (int i = N; i >= 1; i--) {
		for (int j = 1; j <= N; j++) {
			for (int k = 2; k < MAX; k++) {
				if (dp[i][j][k] != 1e9) return i;
			}
		}
	}
}

int main() { //그림 교환
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	cout << solve();
}