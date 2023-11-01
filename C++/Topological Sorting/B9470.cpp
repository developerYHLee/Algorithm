#include <iostream>
#include <cmath>
#include <memory.h>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int degree[1001], res[1001];
vector<vector<int>> map;

void topological_sort(int N) {
	priority_queue<pii, vector<pii>, greater<pii>> PQ;

	for (int i = 1; i <= N; i++) {
		if (!degree[i]) PQ.push({ 1, i });
	}

	while (!PQ.empty()) {
		pii cur = PQ.top();
		PQ.pop();

		int cost = cur.first, node = cur.second;

		for (int next : map[node]) {
			if (degree[next] > 1) res[next] = max(res[next], cost);
			else {
				if (res[next] == cost) res[next]++;
				else res[next] = cost;
				PQ.push({ res[next], next });
			}
			//cout << node << " " << next << " " << res[next] << endl;

			degree[next]--;
		}
	}
}

int main() { //Strahler ¼ø¼­
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T-- > 0) {
		int t, N, M;
		cin >> t >> N >> M;

		memset(degree, 0, sizeof(degree));
		memset(res, 0, sizeof(res));
		map.clear();
		map.assign(N + 1, vector<int>());

		for (int i = 0; i < M; i++) {
			int n1, n2;
			cin >> n1 >> n2;

			map[n1].push_back(n2);
			degree[n2]++;
		}

		topological_sort(N);
		cout << t << " " << res[N] << '\n';
	}
}