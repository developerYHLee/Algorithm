#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string dp[10001];

string cal(string str1, string str2) {
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	while (str1.length() < str2.length()) str1 += '0';
	while (str2.length() < str1.length()) str2 += '0';
	
	string res;
	int p = 0;
	for (int i = 0; i < str1.length(); i++) {
		int temp = str1[i] - '0' + str2[i] - '0' + p;
		res += to_string(temp % 10);
		p = temp / 10;
	}

	if (p > 0) res += to_string(p);

	reverse(res.begin(), res.end());

	return res;
}

int main() { //피보나치 수 4
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	dp[0] = "0";
	dp[1] = "1";

	for (int i = 2; i <= N; i++) dp[i] = cal(dp[i - 1], dp[i - 2]);

	cout << dp[N];
}