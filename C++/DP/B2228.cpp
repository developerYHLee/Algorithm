#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

int N, M, dp[101][101], arr[101];
bool vis[101][101];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	for (int i = 0; i <= 100; i++) fill_n(dp[i], 101, INT_MIN);
}

int recur(int index, int m) {
	if (index > N) return INT_MIN;

	if (vis[index][m]) return dp[index][m];
	vis[index][m] = true;
	
	if(m == 1) dp[index][m] = arr[index];
	
	if (m > 1) {
		for (int i = 2; i <= N - index; i++) {
			int r = recur(index + i, m - 1);
			if(r != INT_MIN) dp[index][m] = max(dp[index][m], r + arr[index]);
		}
	}

	int r = recur(index + 1, m);
	if(r != INT_MIN) dp[index][m] = max(dp[index][m], r + arr[index]);

	return dp[index][m];
}

void solve() {
	recur(1, M);

	int res = INT_MIN;
	for (int i = 1; i <= N; i++) res = max(res, dp[i][M]);

	cout << res;
}

int main() { //구간 나누기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}