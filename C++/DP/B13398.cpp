#include <iostream>
#include <algorithm>

using namespace std;

int N, res, dp[100'001][2], arr[100'001];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
}

void solve() {
	for (int i = 1; i <= N; i++) {
		dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
	}

	res = dp[1][0];
	for (int i = 2; i <= N; i++) res = max({ res, dp[i][0], dp[i][1] });

	cout << res;
}

int main() { //¿¬¼ÓÇÕ 2
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}