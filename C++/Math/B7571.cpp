#include <iostream>
#include <algorithm>

using namespace std;

int N, M, x[100000], y[100000];

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) cin >> x[i] >> y[i];
	sort(x, x + M);
	sort(y, y + M);
}

void solve() {
	int res = 0;
	for (int i = 0; i < M; i++) res += abs(x[i] - x[M / 2]) + abs(y[i] - y[M / 2]);
	cout << res;
}

int main() { //점 모으기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}