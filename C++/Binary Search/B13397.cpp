#include <iostream>
#include <cmath>

using namespace std;

int N, M, arr[5000];

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
}

void solve() {
	int l = 0, r = 10000;

	while (l < r) {
		int m = (l + r) / 2;
		int key = 1, b = 0, s = 10001;
	
		for (int i = 0; i < N; i++) {
			b = max(b, arr[i]);
			s = min(s, arr[i]);

			if (b - s > m) {
				key++;
				b = arr[i];
				s = arr[i];
			}
		}

		if (key > M) l = m + 1;
		else r = m;
	}

	cout << l;
}

int main() { //구간 나누기 2
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}