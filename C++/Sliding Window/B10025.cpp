#include <iostream>
#include <cmath>

using namespace std;

int N, K, G[1'000'001];

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int g, x;
		cin >> g >> x;

		G[x] = g;
	}
	K = K * 2 + 1;
}

void solve() {
	int l = 0, r = 0, res = 0, temp = 0;
	while(r <= 1'000'000) {
		if (r - l >= K) {
			temp -= G[l++];
		}
		temp += G[r++];
		res = max(res, temp);
	}
	cout << res;
}

int main() { //°ÔÀ¸¸¥ ¹é°õ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}