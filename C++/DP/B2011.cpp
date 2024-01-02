#include <iostream>

using namespace std;

const int MOD = 1e6;
int dp[5001];
string num;

void input() {
	cin >> num;
}

bool check(int n) {
	return n <= 26;
}

int make_n(char n1, char n2) {
	return (n1 - '0') * 10 + n2 - '0';
}

int solve() {
	if (num[0] == '0') return 0;

	dp[0] = 1;
	dp[1] = 1;

	for (int i = 1; i < num.size(); i++) {
		int n = make_n(num[i - 1], num[i]);
		if (!n || (num[i] == '0' && n >= 30)) return 0;
		else if (num[i] == '0') dp[i + 1] = dp[i - 1];
		else if (!check(n) || num[i - 1] == '0') dp[i + 1] = dp[i];
		else dp[i + 1] = (dp[i - 1] + dp[i]) % MOD;
	}

	return dp[num.size()];
}

int main() { //암호코드
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	cout << solve();
}