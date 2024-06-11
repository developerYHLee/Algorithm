#include <iostream>

using namespace std;

int N, M;

void input() {
	cin >> N >> M;
}

int recur(int n, int m) {
	if (!n) return 0;
	if (m % n == 0) return (m - 1) / n * n;
	else if (m > n) return m / n * n + recur(n, m % n);
	else return recur(n % m, m);
}

void solve() {
	cout << recur(N, M);
}

int main() { //음식 평론가
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}