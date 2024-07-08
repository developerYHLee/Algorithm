#include <iostream>

using namespace std;

int N, M, K, A[10001], parent[10001];
bool vis[10001];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (A[x] <= A[y]) parent[y] = x;
	else parent[x] = y;
}

void input() {
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		merge(x, y);
	}
}

void solve() {
	int tempK = K;

	for (int i = 1; i <= N; i++) {
		int p = find(i);
		if (!vis[p]) {
			vis[p] = true;
			tempK -= A[p];
		}

		if (tempK < 0) {
			cout << "Oh no";
			return;
		}
	}

	cout << K - tempK;
}

int main() { //Ä£±¸ºñ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}