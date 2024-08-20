#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 1 << 15;
int dp[MAX][5];

void input() {
	int N;
	cin >> N;

	while (N) {
		int res = 0;
		for (int i = 1; i <= 4; i++) res += dp[N][i];
		cout << res << "\n";

		cin >> N;
	}
}

void solve() {
	for (int i = 1; i * i < MAX; i++) {
		dp[i * i][1] = 1;
		
		for (int k = 2; k <= 4; k++) {
			for (int j = MAX - 1; j > i * i; j--) dp[j][k] += dp[j - i * i][k - 1];
		}
	}
}

int main() { //라그랑주의 네 제곱수 정리
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();
	input();
}