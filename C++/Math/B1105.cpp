#include <iostream>
#include <cmath>

using namespace std;

int L, R, res;

void input() {
	cin >> L >> R;
}

int getSz(int num) {
	int ret = 0;

	while (num) {
		ret++;
		num /= 10;
	}

	return ret;
}

void solve() {
	int szL = getSz(L), szR = getSz(R);

	if (szL != szR) {
		cout << 0;
		return;
	}

	while (szL--) {
		int tempL = L / (int)pow(10, szL), tempR = R / (int)pow(10, szL);
		
		if (tempL != tempR) {
			cout << res;
			return;
		}

		if (tempL == 8) res++;

		L %= (int)pow(10, szL);
		R %= (int)pow(10, szL);
	}

	cout << res;
}

int main() { //ÆÈ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}