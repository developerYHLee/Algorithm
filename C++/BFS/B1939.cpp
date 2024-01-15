#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int N, M, factory[2], W[10001];
bool vis[10001];
map<int, int> bridge[10001];

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;

		if (bridge[A].find(B) == bridge[A].end()) bridge[A].insert({ B,C });
		else bridge[A][B] = max(bridge[A][B], C);
		if (bridge[B].find(A) == bridge[B].end()) bridge[B].insert({ A,C });
		else bridge[B][A] = max(bridge[B][A], C);
	}

	cin >> factory[0] >> factory[1];
}

void bfs() {
	int res = 0;

	priority_queue<pii> PQ;
	PQ.push({ 2e9, factory[0] });

	while (!PQ.empty()) {
		pii node = PQ.top();
		PQ.pop();

		int weight = node.first, cur = node.second;
		if (cur == factory[1]) {
			cout << weight;
			return;
		}

		if (vis[cur]) continue;
		vis[cur] = true;

		for (pii next_node : bridge[cur]) {
			int next = next_node.first, w = next_node.second;
			
			int m_w = min(weight, w);
			if (W[next] < m_w) {
				PQ.push({ m_w, next });
				W[next] = m_w;
			}
		}
	}
}

int main() { //중량제한
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	bfs();
}