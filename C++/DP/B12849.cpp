#include <iostream>

using namespace std;
typedef long long ll;

const ll MOD = 1'000'000'007;
ll dp[8], temp[8];
int D;

void input() {
	cin >> D;
	dp[0] = 1;
}

void solve() {
	while (D--) {
		temp[0] = dp[1] + dp[2];
		temp[1] = dp[0] + dp[2] + dp[3];
		temp[2] = dp[0] + dp[1] + dp[3] + dp[4];
		temp[3] = dp[1] + dp[2] + dp[4] + dp[5];
		temp[4] = dp[2] + dp[3] + dp[5] + dp[6];
		temp[5] = dp[3] + dp[4] + dp[7];
		temp[6] = dp[4] + dp[7];
		temp[7] = dp[5] + dp[6];

		for (int i = 0; i < 8; i++) dp[i] = temp[i] % MOD;
	}

	cout << dp[0];
}

int main() { //본대 산책
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}