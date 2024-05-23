#include <iostream>
#include <queue>

using namespace std;

int N;
queue<int> Q;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		Q.push(n);
	}
}

void solve() {
	int res = 0;

	while (Q.size() > 1) {
		int n1 = Q.front();
		Q.pop();

		int n2 = Q.front();
		Q.pop();

		res += n1 * n2;
		Q.push(n1 + n2);
	}

	cout << res;
}

int main() { //슬라임 합치기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}