#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int degree[501], cost[501], res[501];
vector<vector<int>> map;
queue<int> Q;

int main() { //게임 개발
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	map.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> cost[i];

		int prev;
		cin >> prev;

		while (prev != -1) {
			map[prev].push_back(i);
			degree[i]++;

			cin >> prev;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) {
			Q.push(i);
			res[i] = cost[i];
		}
	}

	while (!Q.empty()) {
		int node = Q.front();
		Q.pop();

		for (int next : map[node]) {
			res[next] = max(res[next], res[node] + cost[next]);
			if (--degree[next] == 0) Q.push(next);
		}
	}

	for (int i = 1; i <= N; i++) cout << res[i] << "\n";
}