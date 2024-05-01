#include <iostream>

using namespace std;

int N, K;

void input() {
	cin >> N >> K;
}

void getP(int& p) {
	while (N < p) p >>= 1;
}

void solve() {
	int p = 1 << 30, cnt = 0;

	while (K > cnt) {
		getP(p);
		N -= p;
		cnt++;

		if (!N) break;
	}

	if (!N) cout << 0;
	else cout << p - N;
}

int main() { //¹°º´
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}