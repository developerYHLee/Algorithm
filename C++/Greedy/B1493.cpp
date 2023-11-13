#include <iostream>
#include <cmath>

#define P2(x) pow(2, x)

using namespace std;
typedef long long ll;

void solve(int, int, int, int);

int cube[21], L, W, H, res;

void input() {
	cin >> L >> W >> H;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;

		cube[A] = B;
	}
}

int find_p(int l, int w, int h, int p) {
	for (int i = p; i >= 0; i--) {
		if (cube[i] && (l >= P2(i) && w >= P2(i) && h >= P2(i))) return i;
	}

	return -1;
}

void solve(int l, int w, int h, int cnt_l, int cnt_w, int cnt_h, int p) {
	solve(l - cnt_l * P2(p), w, h, p);
	solve(cnt_l * P2(p), w - cnt_w * P2(p), h, p);
	solve(cnt_l * P2(p), cnt_w * P2(p), h - cnt_h * P2(p), p);
}

void solve(int l, int w, int h, int p) {
	if (l == 0 || w == 0 || h == 0) return;
	
	int m = find_p(l, w, h, p);
	if (m == -1) {
		res = -1;
		return;
	}

	ll cnt_l = l / P2(m), cnt_w = w / P2(m), cnt_h = h / P2(m);
	while (cnt_l > cube[m]) cnt_l /= 2;
	while (cnt_l * cnt_w > cube[m]) cnt_w /= 2;
	while (cnt_l * cnt_w * cnt_h > cube[m]) cnt_h /= 2;

	res += cnt_l * cnt_w * cnt_h;
	cube[m] -= cnt_l * cnt_w * cnt_h;
	solve(l, w, h, cnt_l, cnt_w, cnt_h, m);
}

int main() { //박스 채우기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve(L, W, H, 20);

	cout << res;
}