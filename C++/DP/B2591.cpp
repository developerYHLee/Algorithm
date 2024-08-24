#include <iostream>
#include <string>

using namespace std;

string str;
int dp[40];

int recur(int index) {
	if (index == str.size()) return 1;
	if (dp[index]) return dp[index];

	if (str[index] == '0') return 0;

	dp[index] += recur(index + 1);

	if (index < str.size() - 1) {
		string temp = "";
		temp += str[index];
		temp += str[index + 1];
		if (stoi(temp) <= 34) dp[index] += recur(index + 2);
	}
	
	return dp[index];
}

int main() { //����ī��
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> str;
	cout << recur(0);
}