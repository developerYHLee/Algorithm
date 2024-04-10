#include <iostream>
#include <cmath>

using namespace std;

int N;
long long dp[101];

void input() {
	cin >> N;

	for (int i = 1; i <= 100; i++) dp[i] = i;
	for (int i = 2; i <= 100; i++) {
		for (int j = i + 3; j <= 100; j++) dp[j] = max(dp[j], dp[i] * (j - i - 1));
	}
}

void solve() { cout << dp[N]; }

int main() { //크리보드
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}