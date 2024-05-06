#include <iostream>

using namespace std;
typedef long long ll;

int N;
ll X, len[51], p[51], res;

void input() {
	cin >> N >> X;
}

void setDp() {
	len[0] = 1;
	p[0] = 1;

	for (int i = 1; i <= 50; i++) {
		len[i] = len[i - 1] * 2 + 3;
		p[i] = p[i - 1] * 2 + 1;
	}
}

void eat() {
	int i = N;
	for (; i >= 1; i--) {
		ll l = len[i] / 2;

		if (X < l) X--;
		else {
			res += p[i - 1];

			if (X == l) return;
			
			X -= l + 1;
			res++;
		}
	}
	if (X > 0 && i == 0) res++;
}

void solve() {
	setDp();
	eat();
	cout << res;
}

int main() { //·¹º§ ÇÜ¹ö°Å
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}