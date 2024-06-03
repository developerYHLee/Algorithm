#include <iostream>

using namespace std;

int N, M, Q, dp[1001][1001];

void input() {
	cin >> N >> M >> Q;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int a;
			cin >> a;

			dp[i][j] += dp[i][j - 1] + a;
		}
	}
}

void solve() {
	for (int i = 0; i < Q; i++) {
		int r1, c1, r2, c2, res = 0;
		cin >> r1 >> c1 >> r2 >> c2;

		for (int j = r1; j <= r2; j++) res += dp[j][c2] - dp[j][c1 - 1];
		cout << (res / ((r2 - r1 + 1) * (c2 - c1 + 1))) << "\n";
	}
}

int main() { //어두운 건 무서워
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}