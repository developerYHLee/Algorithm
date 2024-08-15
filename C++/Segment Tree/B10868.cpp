#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 1e9 + 1;
int N, M, tree[410'000], arr[100'001];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> arr[i];
}

int makeTree(int l, int r, int index) {
	if (l == r) return tree[index] = arr[l];

	int m = (l + r) / 2;
	return tree[index] = min(makeTree(l, m, index * 2), makeTree(m + 1, r, index * 2 + 1));
}

int printMin(int s, int e, int l, int r, int index) {
	if (e < l || r < s) return MAX;
	if (s <= l && r <= e) return tree[index];

	int m = (l + r) / 2;
	return min(printMin(s, e, l, m, index * 2), printMin(s, e, m + 1, r, index * 2 + 1));
}

void solve() {
	makeTree(1, N, 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		cout << printMin(a, b, 1, N, 1) << "\n";
	}
}

int main() { //ÃÖ¼Ú°ª
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}