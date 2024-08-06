#include <iostream>

using namespace std;

int N, M, K, dp[226];

void input() {
	cin >> N >> M >> K;
}

int recur(int index, bool vis) {
	if (index > K && !vis) return 0;
	if (index == N * M) return 1;
	
	if (dp[index]) return dp[index];

	if (index % M != 0) {
		if (index + 1 == K) dp[index] += recur(index + 1, true || vis);
		else dp[index] += recur(index + 1, false || vis);
	}
	if (index + M <= N * M) {
		if(index + M == K) dp[index] += recur(index + M, true || vis);
		else dp[index] += recur(index + M, false || vis);
	}
	
	return dp[index];
}

void solve() {
	if(K) cout << recur(1, false);
	else cout << recur(1, true);
}

int main() { //격자상의 경로
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}