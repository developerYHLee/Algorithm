#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int N;
ll dp[1'000'001];

void input() {
	cin >> N;
}

void solve() {
	for (int i = 1; i <= 1000; i++) {
		for (int j = i * i; j <= 1'000'000; j += i) {
			dp[j] += i;
			if (i * i != j) dp[j] += j / i;
		}
	}

	for (int i = 1; i <= 1'000'000; i++) dp[i] += dp[i - 1];
}

int main() { //약수의 합
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();

	int T;
	cin >> T;

	while (T-- > 0) {
		input();
		cout << dp[N] << "\n";
	}
}