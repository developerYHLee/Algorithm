#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> map;
int dp[10001][2], num[10001];

void solve(int prev, int index) {
	dp[index][0] = num[index];

	for (int i : map[index]) {
		if (i == prev) continue;

		solve(index, i);
		dp[index][0] += dp[i][1];
		dp[index][1] += max(dp[i][0], dp[i][1]);
	}
}

int main() { //우수 마을
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) cin >> num[i];
	
	map.resize(N + 1);
	for (int i = 0; i < N - 1; i++) {
		int n1, n2;
		cin >> n1 >> n2;

		map[n1].push_back(n2);
		map[n2].push_back(n1);
	}

	solve(0, 1);
	
	cout << max(dp[1][0], dp[1][1]);
}