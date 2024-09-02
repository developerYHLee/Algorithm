#include <iostream>

using namespace std;

int N, L, D;

void input() {
	cin >> N >> L >> D;
}

void solve() {
	int t1 = 0, t2 = 0;

	for (int i = 0; i < N; i++) {
		t1 += L;

		while (t1 > t2) t2 += D;

		t1 += 5;

		if (t1 > t2) {
			cout << t2;
			return;
		}
	}

	cout << t2;
}

int main() { //부재중 전화
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}