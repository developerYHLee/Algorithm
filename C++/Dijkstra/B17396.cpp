#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

struct Node {
	int x;
	ll d;

	Node(int x, ll d) : x(x), d(d) {}

	bool operator<(Node o) const { return d > o.d; }
};

int N, M;
ll dis[100000];
bool enemy[100000];
vpii E[100000];

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> enemy[i];
	for (int i = 0; i < M; i++) {
		int s, e, d;
		cin >> s >> e >> d;

		E[s].push_back({ e, d });
		E[e].push_back({ s, d });
	}
	fill_n(dis, N, 1e11);
}

void solve() {
	priority_queue<Node> PQ;
	PQ.push(Node(0, 0));
	dis[0] = 0;

	while (!PQ.empty()) {
		Node node = PQ.top();
		PQ.pop();

		int x = node.x;
		ll d = node.d;

		if (x == N - 1) {
			cout << d;
			return;
		}

		if (enemy[x] || dis[x] < d) continue;

		for (pii n : E[x]) {
			int next = n.first, distance = n.second;
			ll temp = dis[x] + distance;
			
			if (dis[next] > temp) {
				dis[next] = temp;
				PQ.push({ next, temp });
			}
		}
	}

	cout << -1;
}

int main() { //¹éµµ¾î
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}