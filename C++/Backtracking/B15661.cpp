#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int N, S[20][20], res;
bool vis[20];

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> S[i][j];
	}

	res = INT_MAX;
}

int calculateStats() {
	int s = 0, l = 0;

	for (int i = 0; i < N; i++) {
		if (vis[i]) {
			for (int j = 0; j < N; j++) {
				if (vis[j]) s += S[i][j];
			}
		}
		else {
			for (int j = 0; j < N; j++) {
				if (!vis[j]) l += S[i][j];
			}
		}
		
	}

	return abs(s - l);
}

void recur(int k) {
	if (k == N) {
		res = min(res, calculateStats());
		return;
	}

	vis[k] = true;
	recur(k + 1);

	vis[k] = false;
	recur(k + 1);
}

void solve() {
	recur(0);
	cout << res;
}

int main() { //링크와 스타트
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}