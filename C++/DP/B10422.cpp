#include <iostream>

using namespace std;
typedef long long ll;

const int MOD = 1'000'000'007;
ll dp[2501];

void setDp() {
	dp[0] = 1;

	for (int i = 1; i <= 2500; i++) {
		for (int j = 1; j <= i; j++) dp[i] = (dp[i] + dp[j - 1] * dp[i - j]) % MOD;
	}
}

int main() { //°ýÈ£
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	setDp();

	int T;
	cin >> T;

	while (T-- > 0) {
		int L;
		cin >> L;

		if (L % 2 != 0) { cout << "0\n"; }
		else cout << dp[L / 2] << "\n";
	}
}