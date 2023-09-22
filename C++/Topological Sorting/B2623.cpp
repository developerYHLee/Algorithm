#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int degree[1001];
vector<vector<int>> map;
vector<int> res;
queue<int> Q;

int main() { //음악프로그램
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	map.resize(N + 1);
	for (int i = 1; i <= M; i++) {
		int m;
		cin >> m;

		int prev;
		cin >> prev;

		for (int j = 1; j < m; j++) {
			int next;
			cin >> next;

			map[prev].push_back(next);
			degree[next]++;

			prev = next;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) Q.push(i);
	}

	for (int i = 1; i <= N; i++) {
		if (Q.empty()) {
			cout << "0";
			return 0;
		}

		int node = Q.front();
		Q.pop();

		res.push_back(node);

		for (int next : map[node]) {
			if (--degree[next] == 0) Q.push(next);
		}
	}

	for (int i : res) cout << i << "\n";
}