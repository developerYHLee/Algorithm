#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

struct Node {
	int x, d;

	Node(int x, int d) : x(x), d(d) {}
	bool operator<(Node o) const { return d > o.d; }
};

int N, M, dis[50001];
vector<pii> path[50001];

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int s, e, d;
		cin >> s >> e >> d;

		path[s].push_back({ e, d });
		path[e].push_back({ s, d });

	}

	fill_n(dis, N + 1, 1e9);
}

void solve() {
	priority_queue<Node> PQ;
	PQ.push({ 1, 0 });
	dis[1] = 0;

	while (!PQ.empty()) {
		Node node = PQ.top();
		PQ.pop();

		int cur = node.x, d = node.d;

		if (cur == N) break;
		if (dis[cur] < d) continue;
	
		for (pii next : path[cur]) {
			int n = next.first, distance = next.second;
			int temp = dis[cur] + distance;
			
			if (dis[n] > temp) {
				dis[n] = temp;
				PQ.push(Node(n, temp));
			}
		}
	}

	cout << dis[N];
}

int main() { //택배 배송
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}