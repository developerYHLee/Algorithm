#include <iostream>
#include <memory.h>

using namespace std;

int N, X[3000], Y[3000], R[3000], parent[3000];
bool vis[3000];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X[i] >> Y[i] >> R[i];
		parent[i] = i;
	}
	memset(vis, false, sizeof(vis));
}

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);

	parent[x] = y;
}

bool checkDis(int i, int j) {
	int p = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
	int r = (R[i] + R[j]) * (R[i] + R[j]);

	if (p > r) return false;
	else return true;
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (!checkDis(i, j)) continue;
			merge(i, j);
		}
	}

	int res = 0;
	for (int i = 0; i < N; i++) {
		int p = find(i);
		if (!vis[p]) {
			vis[p] = true;
			res++;
		}
	}
	cout << res << "\n";
}

int main() { //Count Circle Groups
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T-- > 0) {
		input();
		solve();
	}
}