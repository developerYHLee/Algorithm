#include <iostream>

using namespace std;
typedef long long ll;

const int MOD = 1e9;
int N;
ll res[20'001];

void solve() {
	res[1] = 1;

	for (int i = 2; i <= 20'000; i++) {
		ll num = res[i - 1] * i;

		while (num % 10 == 0) num /= 10;
		res[i] = num % MOD;
	}
}

int main() { //마지막 팩토리얼 수
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();

	cin >> N;
	cout << res[N] % 10;
}