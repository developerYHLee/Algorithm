#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

struct Node {
	int x, r;

	Node(int x, int r) : x(x), r(r) {}
};

int N, M, dp[1001], t[1001];
string path[1001];
vector<Node> edge[1001];

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int p, q, r;
		cin >> p >> q >> r;

		edge[p].push_back(Node(q, r));
		t[q]++;
	}
}

void solve() {
	queue<int> Q;
	Q.push(1);
	path[1] = "1 ";

	while (!Q.empty()) {
		int node = Q.front();
		Q.pop();

		for (Node next : edge[node]) {
			int nextNode = next.x, distance = next.r;

			if (dp[nextNode] < dp[node] + distance) {
				dp[nextNode] = dp[node] + distance;
				path[nextNode] = path[node] + to_string(nextNode) + " ";
			}

			if (--t[nextNode] == 0) Q.push(nextNode);
		}
	}

	cout << dp[1] << "\n" << path[1];
}

int main() { //자동차경주
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}