#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <climits>

using namespace std;

struct Node {
	int a, s;

	Node(int a, int s) : a(a), s(s) {}

	bool operator<(const Node& r) const {
		return r.s < s;
	}
};

int N, D, C, dp[10001];
vector<Node> E[10001];
bool vis[10001];

void input() {
	cin >> N >> D >> C;

	for (int i = 1; i <= N; i++) E[i].clear();

	for (int i = 0; i < D; i++) {
		int a, b, s;
		cin >> a >> b >> s;
	
		E[b].push_back(Node(a, s));
	}
	fill_n(dp, N + 1, INT_MAX);
	memset(vis, false, sizeof(vis));
}

void solve() {
	int cnt = 0, t = 0;
	
	priority_queue<Node> PQ;
	PQ.push(Node(C, 0));
	dp[C] = 0;

	while (!PQ.empty()) {
		Node node = PQ.top();
		PQ.pop();

		int x = node.a, s = node.s;

		if (vis[x]) continue;

		vis[x] = true;
		t = max(t, s);
		cnt++;

		for (Node next : E[x]) {
			int nextX = next.a, spend = next.s;

			if (dp[nextX] > dp[x] + spend) {
				dp[nextX] = dp[x] + spend;
				PQ.push(Node(nextX, dp[nextX]));
			}
		}
	}

	cout << cnt << " " << t << "\n";
}

int main() { //ÇØÅ·
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	
	while (T--) {
		input();
		solve();
	}
}