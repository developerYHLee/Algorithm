#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

struct comp {
	bool operator()(const int& o1, const int& o2) const { return o1 > o2; }
};

set<int, comp> S;
int N, K, dp[10001];

void input() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		S.insert(num);
	}
}

void solve() {
	fill_n(dp, 10001, 1e9);
	dp[0] = 0;
	
	for (auto s : S) {
		for (int i = s; i <= K; i++) dp[i] = min(dp[i], dp[i - s] + 1);
	}
}

int main() { //µ¿Àü 2
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
	cout << (dp[K] == 1e9 ? -1 : dp[K]);
}