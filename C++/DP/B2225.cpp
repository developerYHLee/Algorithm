#include <iostream>

using namespace std;

const int MOD = 1000000000;
int dp[201][201], N, K;

void input() {
	cin >> N >> K;
}

int make_dp() {
	for (int i = 0; i <= 200; i++) dp[1][i] = 1;
	for (int i = 2; i <= 200; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= 200; j++) dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
	}

	return dp[K][N];
}

int main() { //ÇÕºÐÇØ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	cout << make_dp();
}