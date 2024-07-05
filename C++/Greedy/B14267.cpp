#include <iostream>
#include <vector>

using namespace std;

int N, M, dp[100001];
vector<int> child[100001];

void input() {
	cin >> N >> M;
	
	int n;
	cin >> n;
	for (int i = 2; i <= N; i++) {
		cin >> n;
		child[n].push_back(i);
	}

	for (int i = 0; i < M; i++) {
		int c, w;
		cin >> c >> w;

		dp[c] += w;
	}
}

void solve() {
	for (int i = 1; i <= N; i++) {
		cout << dp[i] << " ";

		for(int c : child[i]) dp[c] += dp[i];
	}
}

int main() { //회사 문화 1
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}