#include <iostream>
#include <cmath>

using namespace std;

int dp[4001][4001];
int main() { //공통 부분 문자열
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str1, str2;
	cin >> str1 >> str2;

	int res = 0;
	for (int i = 1; i <= str1.size(); i++) {
		int i1 = i - 1;

		for (int j = 1; j <= str2.size(); j++) {
			int i2 = j - 1;

			if (str1[i1] == str2[i2]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				res = max(res, dp[i][j]);
			}
		}
	}

	cout << res;
}