#include <iostream>
#include <cmath>

using namespace std;

int dp[1001][1001];

void make_dp(string str1, string str2) {
	int size1 = size(str1), size2 = size(str2);
	
	for (int i = 1; i <= size1; i++) {
		char c1 = str1[i - 1];

		for (int j = 1; j <= size2; j++) {
			char c2 = str2[j - 1];

			if (c1 == c2) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
}

int* search(int row, int col) {
	int l = dp[row][col];

	if (dp[row - 1][col - 1] == l) return new int[] { row - 1, col - 1 };
	else if (dp[row - 1][col] == l) return new int[] { row - 1, col };
	else if (dp[row][col - 1] == l) return new int[] { row, col - 1 };
	else return new int[] { row, col };
}

void get_lcs(string str, int size1, int size2) {
	int l = dp[size1][size2];

	if (l == 0) {
		cout << "0";
		return;
	}

	char* lcs = new char[l + 1];
	int row = size1, col = size2;
	while (true) {
		int newLen = dp[row][col];
		int* loc = search(row, col);

		if (loc[0] == row && loc[1] == col) {
			lcs[newLen] = str[row - 1];

			if (newLen == 1) break;
			
			row--;
			col--;
		}
		else {
			row = loc[0];
			col = loc[1];
		}
	}

	cout << l << "\n";
	for (int i = 1; i <= l; i++) cout << lcs[i];
}

int main() { //LCS 2
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str1, str2;
	cin >> str1 >> str2;

	make_dp(str1, str2);
	get_lcs(str1, size(str1), size(str2));
}