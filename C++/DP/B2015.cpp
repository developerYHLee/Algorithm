#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;

int N, K, dp[200'001];

void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;

		dp[i] += dp[i - 1] + n;
	}
}

void solve() {
	ll res = 0;
	unordered_map<int, int> M;
	for (int i = 1; i <= N; i++) {
		if (dp[i] == K) res++;
		res += M[dp[i] - K];
		M[dp[i]]++;
	}
	cout << res;
}

int main() { //수들의 합 4
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}