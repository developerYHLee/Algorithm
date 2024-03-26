#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, K, dp[10001];
vector<int> info[100];

bool cmp(vector<int> o1, vector<int> o2) {
	return o1[0] < o2[0];
}

void input() {
	cin >> T >> K;
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		
		info[i].push_back(a);
		info[i].push_back(b);
	}
	sort(info, info + K, cmp);

	dp[0] = 1;
}

void solve() {
	for (int i = 0; i < K; i++) {
		for (int j = T; j >= 0; j--) {
			for (int k = 1; k <= info[i][1]; k++) {
				int p = info[i][0] * k;

				if (j + p > T) continue;
				dp[j + p] += dp[j];
			}
		}
	}

	cout << dp[T];
}

int main() { //동전 바꿔주기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}