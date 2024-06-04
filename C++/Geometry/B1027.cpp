#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int N, H[50], res;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> H[i];
}

int getCCW(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll ret = (x2 - x1) * (y3 - y2) - (y2 - y1) * (x3 - x2);
	
	if (ret > 0) return 1;
	else if (ret < 0) return -1;
	else return 0;
}

void solve() {
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		int x1 = i, y1 = H[i];

		for (int j = 0; j < i; j++) {
			bool ch = false;
			int x2 = j, y2 = H[j];

			for (int k = j + 1; k < i; k++) {
				int ccw = getCCW(x1, y1, x2, y2, k, H[k]) * getCCW(x1, y1, x2, y2, k, 0);
				
				if (ccw <= 0) {
					ch = true;
					break;
				}
			}

			if (!ch) cnt++;
		}

		for (int j = i + 1; j < N; j++) {
			bool ch = false;
			int x2 = j, y2 = H[j];

			for (int k = j - 1; k > i; k--) {
				int ccw = getCCW(x1, y1, x2, y2, k, H[k]) * getCCW(x1, y1, x2, y2, k, 0);

				if (ccw <= 0) {
					ch = true;
					break;
				}
			}

			if (!ch) cnt++;
		}

		res = max(res, cnt);
	}

	cout << res;
}

int main() { //°íÃþ °Ç¹°
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}