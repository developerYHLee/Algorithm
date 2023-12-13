#include <iostream>
#include <algorithm>

using namespace std;

int dp[16][1 << 16], W[16][16], max_bit, N;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> W[i][j];
	}

	max_bit = (1 << N) - 1;
}

int dfs(int node, int vis_bit) {
	if (vis_bit == max_bit) return W[node][0] ? W[node][0] : 1e9;

	if (dp[node][vis_bit]) return dp[node][vis_bit];
	dp[node][vis_bit] = 1e9;

	for (int i = 0; i < N; i++) {
		if (!W[node][i] || (vis_bit & (1 << i))) continue;

		dp[node][vis_bit] = min(dp[node][vis_bit], W[node][i] + dfs(i, vis_bit | (1 << i)));
	}

	return dp[node][vis_bit];
}

int main() { //외판원 순회
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	cout << dfs(0, 1);
}