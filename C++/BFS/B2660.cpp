#include <iostream>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <vector>
#include <memory.h>

using namespace std;
typedef pair<int, int> pii;

int N, minScore = 1e9;
vector<int> E[51];
unordered_map<int, vector<int>> M;
bool vis[51];

void input() {
	cin >> N;
	
	while (true) {
		int a, b;
		cin >> a >> b;

		if (a == -1 && b == -1) break;
		
		E[a].push_back(b);
		E[b].push_back(a);
	}
}

int bfs(int member) {
	queue<pii> Q;
	Q.push({ member, 0 });
	vis[member] = true;

	int ret = 0;
	while (!Q.empty()) {
		pii node = Q.front();
		Q.pop();

		int m = node.first, cnt = node.second;

		for (int next : E[m]) {
			if (vis[next]) continue;
			vis[next] = true;

			Q.push({ next, cnt + 1 });
			ret = max(ret, cnt + 1);
		}
	}

	return ret;
}

void solve() {
	for (int i = 1; i <= N; i++) {
		memset(vis, false, sizeof(vis));

		int score = bfs(i);
		M[score].push_back(i);
		minScore = min(minScore, score);
	}

	cout << minScore << " " << M[minScore].size() << "\n";
	for (int i : M[minScore]) cout << i << " ";
}

int main() { //È¸Àå»Ì±â
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}