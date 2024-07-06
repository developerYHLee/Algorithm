#include <iostream>

using namespace std;
typedef long long ll;

string str, bridge[2];
int dp[2][100][20];

void input() {
	cin >> str >> bridge[0] >> bridge[1];
}

int recur(bool angel, int bIndex, int sIndex) {
	if (sIndex == str.size()) return 1;

	int ret = 0;

	for (int i = bIndex; i < bridge[0].size(); i++) {
		if (bridge[angel][i] != str[sIndex]) continue;
		
		if(!dp[angel][i][sIndex]) dp[angel][i][sIndex] += recur(!angel, i + 1, sIndex + 1);
		ret += dp[angel][i][sIndex];
	}

	return ret;
}

void solve() {
	cout << recur(true, 0, 0) + recur(false, 0, 0);
}

int main() { //돌다리 건너기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}