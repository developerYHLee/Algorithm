#include <iostream>

using namespace std;
typedef long long ll;

const int MAX = 1e6 + 1;
ll dp[MAX];
int dp_M[1000];

int main() { //나머지 합
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		ll n;
		cin >> n;

		dp[i] = dp[i - 1] + n;
	}

	ll res = 0;
	for (int i = 1; i <= N; i++) {
		if (dp[i] % M == 0) res++;
		res += dp_M[dp[i] % M]++;
	}

	cout << res;
}