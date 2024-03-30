#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 1500002;
int N, dp[MAX];

void solve() {
	cin >> N;

	int res = 0;
	for (int i = 1; i <= N; i++) {
		int t, p;
		cin >> t >> p;

		dp[i] = max(dp[i], dp[i - 1]);

		if (i + t > N + 1) continue;
		dp[i + t] = max(dp[i + t], dp[i] + p);
	}
	res = max(dp[N], dp[N + 1]);

	cout << res;
}

int main() { //Επ»η 2
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
}