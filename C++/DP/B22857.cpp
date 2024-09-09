#include <iostream>
#include <cmath>

using namespace std;

int N, K, arr[50'001], dp[50'000][101];

void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> arr[i];
}

void solve() {
	int res = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (arr[i] % 2 == 0) dp[i][j] = dp[i - 1][j] + 1;
			else if(j > 0) dp[i][j] = dp[i - 1][j - 1];
		
			res = max(res, dp[i][j]);
		}
	}

	cout << res;
}

int main() { //가장 긴 짝수 연속한 부분 수열 (small)
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}