#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int N, M;

void solve() {
	ll ret = 1;
	M = min(M, N - M);

	for (int i = 0; i < M; i++) {
		ret *= (ll)N - i;
		ret /= (ll)i + 1;
	}

	cout << ret << "\n";
}

int main() { //ÀÌÇ× ¼î´Ù¿î
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	while (N || M) {
		solve();
		cin >> N >> M;
	}
}