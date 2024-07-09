#include <iostream>
#include <queue>
#include <vector>0

using namespace std;

int N, M, res;
vector<int> E[501];
bool vis[501];

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;

		E[n1].push_back(n2);
		E[n2].push_back(n1);
	}
}

void solve() {
	queue<pair<int, int>> Q;
	Q.push({ 1, 0 });
	vis[1] = true;

	while (!Q.empty()) {
		pair<int, int> node = Q.front();
		Q.pop();

		int x = node.first, cnt = node.second;

		if (cnt == 2) continue;

		for (int i : E[x]) {
			if (vis[i]) continue;
		
			Q.push({ i, cnt + 1 });
			vis[i] = true;

			res++;
		}
	}

	cout << res;
}

int main() { //°áÈ¥½Ä
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}