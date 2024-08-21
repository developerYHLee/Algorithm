#include <iostream>

using namespace std;

int dp[10'001];

void makeDp() {
	for (int i = 0; i <= 10'000; i++) dp[i] = 1;
	for (int i = 2; i <= 10'000; i++) dp[i] += dp[i - 2];
	for (int i = 3; i <= 10'000; i++) dp[i] += dp[i - 3];
}

int main() { //1, 2, 3 ´õÇÏ±â 4
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	makeDp();

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;
		cout << dp[N] << "\n";
	}
}