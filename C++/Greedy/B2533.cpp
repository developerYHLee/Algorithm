#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool vis[1000001];
int dp[1000001][2];
vector<vector<int>> map;

void solve(int index) {
	vis[index] = true;
	dp[index][1] = true;

	for (int i : map[index]) {
		if (vis[i]) continue;

		solve(i);
		dp[index][0] += dp[i][1];
		dp[index][1] += min(dp[i][0], dp[i][1]);
	}
}

int main() { //사회망 서비스(SNS) (DP)
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	map.resize(N + 1);
	for (int i = 0; i < N - 1; i++) {
		int n1, n2;
		cin >> n1 >> n2;

		map[n1].push_back(n2);
		map[n2].push_back(n1);
	}

	solve(1);
	cout << (min(dp[1][0], dp[1][1]));
}