#include <iostream>
#include <cmath>

using namespace std;

int dp[2501];
bool palindrome[2501][2501];
string str;

inline bool isPalindrome(int s, int e) {
	return (e == s + 1 ? true : palindrome[s + 1][e - 1]);
}

void make_palindrome(int N) {
	for (int i = 1; i <= N; i++) palindrome[i][i] = true;

	for (int i = N - 1; i > 0; i--) {
		for (int j = i + 1; j <= N; j++) {
			if (str[i] == str[j]) palindrome[i][j] = isPalindrome(i, j);
		}
	}
}

int solve(int N) {
	for (int i = 1; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;

		for (int j = 1; j < i; j++) {
			if (str[i] == str[j] && isPalindrome(j, i)) dp[i] = min(dp[i], dp[j - 1] + 1);
		}
	}

	return dp[N];
}

int main() { //팰린드롬 분할
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;
	str = " " + str;
	int N = str.size() - 1;
	make_palindrome(N);
	cout << solve(N);
}