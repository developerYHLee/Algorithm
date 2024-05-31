#include <iostream>

using namespace std;
typedef long long ll;

struct Pos {
	ll x, y;

	Pos() {};
	Pos(ll x, ll y) : x(x), y(y) {}

	bool operator<=(const Pos& o) {
		if (x == o.x) return y <= o.y;
		return x <= o.x;
	}
};

Pos pos[4];

void input() {
	for (int i = 0; i < 4; i++) {
		ll x, y;
		cin >> x >> y;

		pos[i] = Pos(x, y);
	}
}

int getCCW(Pos a, Pos b, Pos c) {
	ll ccw = (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);

	if (ccw > 0) return 1;
	else if (ccw < 0) return -1;
	else return 0;
}

void solve() {
	int o1 = getCCW(pos[0], pos[1], pos[2]) * getCCW(pos[0], pos[1], pos[3]);
	int o2 = getCCW(pos[2], pos[3], pos[0]) * getCCW(pos[2], pos[3], pos[1]);

	if (o1 == 0 && o2 == 0) {
		if (pos[1] <= pos[0]) swap(pos[0], pos[1]);
		if (pos[3] <= pos[2]) swap(pos[2], pos[3]);

		if (pos[0] <= pos[3] && pos[2] <= pos[1]) cout << 1;
		else cout << 0;
	}
	else if (o1 <= 0 && o2 <= 0) cout << 1;
	else cout << 0;
}

int main() { //선분 교차 2
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}