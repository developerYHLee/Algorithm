#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int N, scv[3], dp[61][61][61], res;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) cin >> scv[i];
	
	res = INT_MAX;
	for (int i = 0; i <= 60; i++) {
		for(int j = 0; j <= 60; j++) fill_n(dp[i][j], 61, INT_MAX);
	}
}

void recur(int x, int y, int z, int cnt) {
	if (x == 0 && y == 0 && z == 0) {
		res = min(res, cnt);
		return;
	}

	if (dp[x][y][z] <= cnt) return;
	dp[x][y][z] = cnt;

	recur(x - 9 > 0 ? x - 9 : 0, y - 3 > 0 ? y - 3 : 0, z - 1 > 0 ? z - 1 : 0, cnt + 1);
	recur(x - 9 > 0 ? x - 9 : 0, y - 1 > 0 ? y - 1 : 0, z - 3 > 0 ? z - 3 : 0, cnt + 1);
	recur(x - 3 > 0 ? x - 3 : 0, y - 9 > 0 ? y - 9 : 0, z - 1 > 0 ? z - 1 : 0, cnt + 1);
	recur(x - 3 > 0 ? x - 3 : 0, y - 1 > 0 ? y - 1 : 0, z - 9 > 0 ? z - 9 : 0, cnt + 1);
	recur(x - 1 > 0 ? x - 1 : 0, y - 9 > 0 ? y - 9 : 0, z - 3 > 0 ? z - 3 : 0, cnt + 1);
	recur(x - 1 > 0 ? x - 1 : 0, y - 3 > 0 ? y - 3 : 0, z - 9 > 0 ? z - 9 : 0, cnt + 1);
}

void solve() {
	recur(scv[0], scv[1], scv[2], 0);
	cout << res;
}

int main() { //¹ÂÅ»¸®½ºÅ©
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}