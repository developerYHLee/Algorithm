#include <iostream>

using namespace std;
typedef long long ll;

ll A, B, dp[50];

void makeDp() {
	dp[0] = 1;

	for (int i = 1; ((ll)1 << i) <= 1e15; i++) {
		dp[i] = ((ll)1 << i);
		for (int j = 0; j < i; j++) dp[i] += dp[j];
	}
}

void input() {
	cin >> A >> B;
}

int getP(ll num) {
	int ret = 0;

	while (((ll)1 << ret) <= num) ret++;

	return ret - 1;
}

ll recur(ll num) {
	if (num == 0) return 0;
	
	int p = getP(num);

	return dp[p] + recur(num - ((ll)1 << p));
}

void solve() {
	makeDp();
	cout << recur(B) - recur(A - 1);
}

int main() { //2로 몇 번 나누어질까
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}