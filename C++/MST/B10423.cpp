#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

vector<int> tempK;
vector<vector<pii> > map;
priority_queue<pii, vector<pii>, greater<pii> > PQ;
int vis[1001];

int prim(int K) {
	for (int i = 0; i < K; i++) {
		int k = tempK[i];
		for (pii node : map[k]) PQ.push(node);
		vis[k] = true;
	}

	int res = 0;
	while (!PQ.empty()) {
		pii cur = PQ.top();
		PQ.pop();

		int node = cur.second, cost = cur.first;
		
		if (vis[node]) continue;
		vis[node] = true;
		res += cost;

		for (pii next : map[node]) {
			int n = next.second;

			if (vis[n]) continue;
			PQ.push(next);
		}
	}

	return res;
}

int main() { //전기가 부족해
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	map.resize(N + 1);
	tempK.resize(K);
	for (int i = 0; i < K; i++) cin >> tempK[i];

	for (int i = 0; i < M; i++) {
		int s, e, c;
		cin >> s >> e >> c;

		map[s].push_back({ c, e });
		map[e].push_back({ c, s });
	}

	cout << prim(K);
}