#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

struct Node {
	int x, d;

	Node(int x, int d) : x(x), d(d) {}
	bool operator<(Node o) const { return d > o.d; }
};

int N, M, S, T, dis[5001];
vector<pii> E[100001];

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int s, e, d;
		cin >> s >> e >> d;

		E[s].push_back({ e,d });
		E[e].push_back({ s,d });
	}
	cin >> S >> T;

	fill_n(dis, N + 1, 1e9);
}

void solve() {
	priority_queue<Node> PQ;
	PQ.push(Node(S, 0));
	dis[S] = 0;

	while (!PQ.empty()) {
		Node node = PQ.top();
		PQ.pop();

		int cur = node.x, distance = node.d;

		if (cur == T) break;
		if (dis[cur] < distance) continue;

		for (pii next : E[cur]) {
			int n = next.first, d = next.second, temp = dis[cur] + d;

			if (dis[n] > temp) {
				dis[n] = temp;
				PQ.push(Node(n, temp));
			}
		}
	}

	cout << dis[T];
}

int main() { //간선 이어가기 2
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}
