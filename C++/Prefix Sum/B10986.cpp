#include <iostream>

using namespace std;
typedef long long ll;

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
		res += dp_M[dp % M]++;
	}

	cout << (res + dp_M[0]);
}