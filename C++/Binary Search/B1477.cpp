#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, L;
vector<int> pos;
void input() {
	cin >> N >> M >> L;
	pos.push_back(0);
	pos.push_back(L);
	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		pos.push_back(p);
	}
	sort(pos.begin(), pos.end());
}

int b_s() {
	int l = 1, r = L;
	while (l < r) {
		int m = (l + r) / 2, p = 0;

		for (int i = 1; i < N + 2; i++) {
			int d = pos[i] - pos[i - 1];
			while (d > m) {
				d -= m;
				p++;
			}
		}

		if (p <= M) r = m;
		else l = m + 1;
	}

	return l;
}

void solve() {
	cout << b_s();
}

int main() { //휴게소 세우기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}