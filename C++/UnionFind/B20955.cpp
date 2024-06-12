#include <iostream>
#include <vector>

using namespace std;

int N, M, parent[100001], res;
vector<int> edge[100001];
bool vis[100001];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) parent[i] = i;
	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;

		edge[n1].push_back(n2);
	}
	res = -1;
}

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) res++;
	else parent[x] = y;
}

void solve() {
	for (int i = 1; i <= N; i++) {
		for (int node : edge[i]) merge(i, node);
	}

	for (int i = 1; i <= N; i++) {
		int p = find(i);
		if (!vis[p]) {
			vis[p] = true;
			res++;
		}
	}
	cout << res;
}

int main() { //민서의 응급 수술
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}