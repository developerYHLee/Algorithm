#include <iostream>
#include <algorithm>

using namespace std;

string S1, S2, S3;
int dp[101][101][101];

void input() {
	cin >> S1 >> S2 >> S3;
	S1 = " " + S1;
	S2 = " " + S2;
	S3 = " " + S3;
}

void solve() {
	for (int i = 1; i < S1.size(); i++) {
		for (int j = 1; j < S2.size(); j++) {
			for (int k = 1; k < S3.size(); k++) {
				if (S1[i] == S2[j] && S1[i] == S3[k]) dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				else dp[i][j][k] = max({ dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1] });
			}
		}
	}

	cout << dp[S1.size() - 1][S2.size() - 1][S3.size() - 1];
}

int main() { //LCS 3
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}