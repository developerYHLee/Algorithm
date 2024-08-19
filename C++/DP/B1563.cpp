#include <iostream>
#include <cmath>

using namespace std;

const int MOD = 1'000'000;
int N, dp[1001][2][3];

void makeDp() {
	dp[1][0][0] = dp[1][1][0] = dp[1][0][1] = 1;

	for (int i = 2; i <= 1000; i++) {
		dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
		dp[i][0][1] = dp[i - 1][0][0];
		dp[i][0][2] = dp[i - 1][0][1];
		dp[i][1][0] = (dp[i][0][0] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % MOD;
		dp[i][1][1] = dp[i - 1][1][0];
		dp[i][1][2] = dp[i - 1][1][1];
	}
}

void solve() {
	makeDp();
	cout << (dp[N][0][0] + dp[N][0][1] + dp[N][0][2] + dp[N][1][0] + dp[N][1][1] + dp[N][1][2]) % MOD;
	
}

int main() { //°³±Ù»ó
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	solve();
}