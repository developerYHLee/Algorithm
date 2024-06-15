#include <iostream>

using namespace std;

const int MOD = 9901;
int dp[100'001], sum[100'001], N;

void input() {
	cin >> N;

	dp[0] = 1;
	dp[1] = 2;
	sum[0] = 1;
	sum[1] = 3;
}

void makeDp() {
	for (int i = 2; i <= N; i++) {
		dp[i] = (dp[i - 1] + sum[i - 2] * 2) % MOD;
		sum[i] = (sum[i - 1] + dp[i]) % MOD;
	}
}

void solve() {
	makeDp();
	cout << sum[N];
}

int main() { //µ¿¹°¿ø
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}