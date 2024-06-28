#include <iostream>

using namespace std;
typedef long long ll;

const int MOD = 1'000'000'007;
int N, M, K, firstIndex;
ll tree[4'000'000];

void setFirstIndex() {
	firstIndex = 1;
	while (firstIndex < N) firstIndex *= 2;
}

void input() {
	cin >> N >> M >> K;
	setFirstIndex();

	for (int i = 0; i < N; i++) cin >> tree[firstIndex + i];
	for (int i = firstIndex - 1; i > 0; i--) tree[i] = (tree[i * 2] * tree[i * 2 + 1]) % MOD;
}

void changeNum(int index, int num) {
	tree[index] = num;
	index /= 2;

	while (index > 0) {
		tree[index] = (tree[index * 2] * tree[index * 2 + 1]) % MOD;
		index /= 2;
	}
}

ll searchTree(int l, int r, int s, int e, int index) {
	if (r < s || l > e) return 1;
	if (s <= l && r <= e) return tree[index];

	int m = (l + r) / 2;
	return (searchTree(l, m, s, e, index * 2) * searchTree(m + 1, r, s, e, index * 2 + 1)) % MOD;
}

void solve() {
	int sz = M + K;
	for (int i = 0; i < sz; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1) changeNum(firstIndex + b - 1, c);
		else if (a == 2) cout << searchTree(1, firstIndex, b, c, 1) << "\n";
	}
}

int main() { //구간 곱 구하기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}