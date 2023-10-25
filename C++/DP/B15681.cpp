#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
const int MAX_INDEX = 1e5 + 1;
int dp[MAX_INDEX];

int solve(int prev, int index) {
	dp[index] = 1;

	for (int i : map[index]) {
		if (i == prev) continue;

		dp[index] += solve(index, i);
	}

	return dp[index];
}

int main() { //Æ®¸®¿Í Äõ¸®
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, R, Q;
	cin >> N >> R >> Q;

	map.resize(N + 1);
	for (int i = 0; i < N - 1; i++) {
		int n1, n2;
		cin >> n1 >> n2;

		map[n1].push_back(n2);
		map[n2].push_back(n1);
	}

	solve(0, R);

	for (int i = 0; i < Q; i++) {
		int U;
		cin >> U;
		
		cout << dp[U] << '\n';
	}
}