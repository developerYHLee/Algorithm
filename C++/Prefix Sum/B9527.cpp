#include <iostream>

using namespace std;
typedef long long ll;

const int MAX = 56;
ll dp[MAX];

ll solve(ll N) {
	ll res = 0;

	for (int i = MAX - 1; i > 0; i--) {
		int index = i - 1;
		if (N & (1LL << index)) {
			res += dp[i - 1] + (N - (1LL << index) + 1);
			N -= 1LL << index;
		}
	}

	return res;
}

int main() { //1의 개수 세기
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll A, B;
	cin >> A >> B;

	dp[1] = 1;
	for (int i = 2; i < MAX; i++) dp[i] = dp[i - 1] * 2 + (1LL << (i - 1));

	cout << (solve(B) - solve(A - 1));
}