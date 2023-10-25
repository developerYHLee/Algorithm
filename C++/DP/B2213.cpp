#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> save_node;
vector<vector<int>> map;
int dp[10001][2], W[10001];

void get_node(int prev, int index, bool include_prev_node) {
	if (include_prev_node) {
		for (int i : map[index]) {
			if (prev == i) continue;

			get_node(index, i, false);
		}
	}
	else {
		for (int i : map[index]) {
			if (prev == i) continue;

			if (dp[i][0] > dp[i][1]) {
				save_node.push_back(i);
				get_node(index, i, true);
			}
			else get_node(index, i, false);
		}
	}
}

void solve(int prev, int index) {
	dp[index][0] = W[index];

	for (int i : map[index]) {
		if (prev == i) continue;

		solve(index, i);
		dp[index][0] += dp[i][1];
		dp[index][1] += max(dp[i][0], dp[i][1]);
	}
}

int main() { //트리의 독립집합
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> W[i];
	
	map.resize(N + 1);
	for (int i = 0; i < N - 1; i++) {
		int n1, n2;
		cin >> n1 >> n2;

		map[n1].push_back(n2);
		map[n2].push_back(n1);
	}

	solve(0, 1);

	if (dp[1][0] > dp[1][1]) {
		cout << dp[1][0] << '\n';
		save_node.push_back(1);
		get_node(0, 1, true);
	}
	else {
		cout << dp[1][1] << '\n';
		get_node(0, 1, false);
	}

	sort(save_node.begin(), save_node.end());
	for (int i = 0; i < save_node.size(); i++) cout << save_node[i] << " ";
}