#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main() { //ACM Craft
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T-- > 0) {
		int N, M;
		cin >> N >> M;

		vector<vector<int>> map(N + 1);
		int* degree = new int[N + 1]{}, * cost = new int[N + 1], * ans = new int[N + 1]{};
		for (int i = 1; i <= N; i++) cin >> cost[i];
		for (int i = 0; i < M; i++) {
			int s, e;
			cin >> s >> e;

			map[s].push_back(e);
			degree[e]++;
		}

		int W;
		cin >> W;

		queue<int> Q;
		for (int i = 1; i <= N; i++) {
			if (degree[i] == 0) Q.push(i);
		}

		for (int i = 1; i <= N; i++) {
			int node = Q.front();
			Q.pop();

			if (node == W) {
				cout << ans[node] + cost[node] << endl;
				break;
			}

			for (const int& next : map[node]) {
				ans[next] = max(ans[next], ans[node] + cost[node]);
				if (--degree[next] == 0) Q.push(next);
			}
		}

		delete[] degree, cost;
	}
}