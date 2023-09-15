#include <iostream>

using namespace std;

int N;
int map[33][33];
long long dp[33][33][3];
int main() { //파이프 옮기기 2
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cin >> map[i][j];
	}

	dp[1][2][0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 3; j <= N; j++) {
			if (map[i][j]) continue;
			dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][1];
			if (!map[i - 1][j] && !map[i][j - 1]) dp[i][j][1] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
			dp[i][j][2] = dp[i - 1][j][1] + dp[i - 1][j][2];
		}
	}

	/*
	cout << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cout << dp[i][j][0] + dp[i][j][1] + dp[i][j][2] << " ";
		cout << endl;
	}
	*/

	cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
}