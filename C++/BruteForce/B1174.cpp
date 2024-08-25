#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

int N, P;
const ll MAX = 987'654'321;
ll dp[1'000'001];

ll setNext(ll num) {
	int p = 0;

	while (true) {
		if (p == P) break;
		
		ll n1 = (num / (ll)pow(10, p)) % 10;
		ll n2 = (num / (ll)pow(10, p + 1)) % 10;

		if (n1 + 1 == n2) p++;
		else {
			ll ret = (num / (ll)pow(10, p + 2)) * 100 + n2 * 10 + n1 + 1;
			
			for (int i = p - 1; i >= 0; i--) ret = ret * 10 + i;
			
			return ret;
		}
	}

	ll n = num / (ll)pow(10, P);
	ll ret = n + 1;

	if (n == 9) ret = ++P;

	for (int i = P - 1; i >= 0; i--) ret = ret * 10 + i;

	return ret;
}

void makeDp() {
	fill_n(dp, 1'000'001, -1);
	dp[1] = 0;
	dp[2] = 1;

	for (int i = 3; i <= 1'000'000; i++) {
		if (dp[i - 1] == MAX) {
			dp[i] = 9'876'543'210;
			return;
		}

		dp[i] = setNext(dp[i - 1]);
	}
}

int main() { //줄어드는 수
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	makeDp();
	cin >> N;
	cout << dp[N];
}