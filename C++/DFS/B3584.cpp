#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int N, parent[10001], n1, n2, res;
bool vis[10001];

void input() {
	memset(vis, false, sizeof(vis));
	res = 0;

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int A, B;
		cin >> A >> B;

		parent[B] = A;
	}
	
	cin >> n1 >> n2;
}

void recur(int node) {
	if (vis[node]) {
		res = node;
		return;
	}

	vis[node] = true;
	recur(parent[node]);
}

void solve() {
	recur(n1);
	recur(n2);
	cout << res << "\n";
}

int main() { //가장 가까운 공통 조상
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