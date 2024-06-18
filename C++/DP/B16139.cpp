#include <iostream>

using namespace std;

string str;
int N, dp[200'001][26];

void makeDp() {
	for (int i = 0; i < str.size(); i++) {
		dp[i + 1][str[i] - 'a']++;
		for (int j = 0; j < 26; j++) dp[i + 1][j] += dp[i][j];
	}
}

void input() {
	cin >> str;
	cin >> N;

	makeDp();

	while (N--) {
		char alpha;
		cin >> alpha;
		
		int a = alpha - 'a';

		int l, r;
		cin >> l >> r;

		cout << dp[r + 1][a] - dp[l][a] << "\n";
	}
}

int main() { //인간-컴퓨터 상호작용
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
}