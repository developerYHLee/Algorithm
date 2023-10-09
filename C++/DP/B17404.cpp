#include <iostream>
#include <cmath>

using namespace std;

int rgb[1000][3];

void print_rgb(const int* dp) {
	for (int i = 0; i < 3; i++) cout << dp[i] << " ";
	cout << endl;
}

void check(int* dp, int prev, int next, int index) {
	int r = min(dp[1], dp[2]) + rgb[index][0];
	int g = min(dp[0], dp[2]) + rgb[index][1];
	int b = min(dp[0], dp[1]) + rgb[index][2];

	dp[0] = r;
	dp[1] = g;
	dp[2] = b;
	
	dp[prev] = 1e9;
	dp[next] = 1e9;
}

int solve(int N, int start, int end) {
	int res = rgb[0][start] + rgb[N - 1][end];
	if (N == 2) return res;

	int* dp = new int[3]{};
	if (N == 3) check(dp, start, end, 1);
	else check(dp, start, start, 1);

	for (int i = 2; i < N - 2; i++) {
		int r = min(dp[1], dp[2]) + rgb[i][0];
		int g = min(dp[0], dp[2]) + rgb[i][1];
		int b = min(dp[0], dp[1]) + rgb[i][2];

		dp[0] = r;
		dp[1] = g;
		dp[2] = b;
	}
	if(N > 3) check(dp, end, end, N - 2);

	res = min(dp[0], min(dp[1], dp[2])) + res;
	return res;
}

int main() { //RGB°Å¸® 2
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) cin >> rgb[i][j];
	}

	int m = 1e9;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j) continue;
		
			m = min(m, solve(N, i, j));
		}
	}
	

	cout << m;
}