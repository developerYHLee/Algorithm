#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;

int N, n1, n2, res;
vector<pii> E[100001];
bool vis[100001];

void input() {
	cin >> N >> n1 >> n2;
	for (int i = 0; i < N - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		E[a].push_back({ b, c });
		E[b].push_back({ a, c });
	}
}

void recur(int node, int maxDis, int total) {
	if (vis[node]) return;
	vis[node] = true;

	if (node == n2) {
		res = total - maxDis;
		return;
	}

	for (pii nNode : E[node]) recur(nNode.first, max(maxDis, nNode.second), total + nNode.second);
}

void solve() {
	recur(n1, 0, 0);
	cout << res;
}

int main() { //µÎ ·Îº¿
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}