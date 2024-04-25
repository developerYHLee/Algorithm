#include <iostream>
#include <algorithm>

using namespace std;

int N, M, T[1001], dp[1001][31][3];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> T[i];
}

void solve() {
	for (int i = 1; i <= N; i++) {
		if (T[i] == 1) dp[i][0][1] = dp[i - 1][0][1] + 1;
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (T[j] == 1) {
				dp[j][i][1] = max(dp[j - 1][i - 1][2], dp[j - 1][i][1]) + 1;
				dp[j][i][2] = dp[j - 1][i][2];
			}
			else {
				dp[j][i][2] = max(dp[j - 1][i - 1][1], dp[j - 1][i][2]) + 1;
				dp[j][i][1] = dp[j - 1][i][1];
			}
		}
	}

	cout << max(dp[N][M][1], dp[N][M][2]);
}

int main() { //자두나무
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}