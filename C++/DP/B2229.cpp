#include <iostream>
#include <cmath>

using namespace std;

int N, arr[1001], dp[1001];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
}

void solve() {
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1];
		for (int j = 1; j < i; j++) dp[i] = max(dp[i], dp[j - 1] + abs(arr[i] - arr[j]));
	}

	cout << dp[N];
}

int main() { //Á¶ Â¥±â
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}