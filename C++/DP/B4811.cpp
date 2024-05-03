#include <iostream>

using namespace std;
typedef long long ll;

ll dp[31];

void solve() {
	dp[0] = 1;
	
	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= i; j++) dp[i] += dp[i - j] * dp[j - 1];
	}
}

void input() {
	int T;
	cin >> T;

	while (T) {
		cout << dp[T] << "\n";
		cin >> T;
	}
}

int main() { //¾Ë¾à
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	input();
}