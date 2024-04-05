#include <iostream>

using namespace std;
typedef long long ll;

const int MOD = 1'000'000'007;
int N;
ll C[1516][1516];

void input() { 
	cin >> N;
	for (int i = 1; i <= 1515; i++) {
		C[i][0] = 1;
		C[i][i] = 1;
	}

	for (int i = 2; i <= 1515; i++) {
		for (int j = 1; j < i; j++) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
	}
}

void solve() {
	ll res = 0;
	for (int i = 0; i < N; i++) {
		int sum = i + (5 * (N - i));

		if (sum % 3 == 0) res = (res + C[N - 1][i]) % MOD;
	}

	cout << res;
}

int main() { //Ezreal 여눈부터 가네 ㅈㅈ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}