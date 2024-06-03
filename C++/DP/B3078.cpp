#include <iostream>

using namespace std;
typedef long long ll;

int N, K, sz[300000];
ll dp[300000][21];

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		sz[i] = str.size();
		dp[i][sz[i]]++;
	}

	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= 20; j++) dp[i][j] += dp[i - 1][j];
	}
}

void solve() {
	ll res = 0;
	for (int i = 0; i < N; i++) {
		if (i + K >= N) res += dp[N - 1][sz[i]] - dp[i][sz[i]];
		else res += dp[i + K][sz[i]] - dp[i][sz[i]];
	}
	cout << res;
}

int main() { //좋은 친구
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}