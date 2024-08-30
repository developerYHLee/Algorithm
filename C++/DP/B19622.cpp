#include <iostream>
#include <cmath>

using namespace std;

int N, arr[100'001], dp[100'001];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[i] = c;
	}
}

void solve() {
	dp[1] = arr[1];
	for (int i = 2; i <= N; i++) dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
	cout << dp[N];
}

int main() { //회의실 배정 3
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}