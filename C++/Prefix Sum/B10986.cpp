#include <iostream>

using namespace std;
typedef long long ll;

const int MAX = 1e6 + 1;
int dp_M[1000];

int main() { //������ ��
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	ll res = 0, dp = 0;
	for (int i = 1; i <= N; i++) {
		ll n;
		cin >> n;

		dp += n;

		if (dp % M == 0) res++;
		res += dp_M[dp % M]++;
	}

	cout << res;
}