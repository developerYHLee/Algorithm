#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() { //¹®Á¦Áý
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int* degree = new int[N + 1]{};
	vector<vector<int>> map(N + 1);
	vector<int> res;
	priority_queue<int, vector<int>, greater<int>> PQ;

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;

		map[s].push_back(e);
		degree[e]++;
	}

	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) PQ.push(i);
	}

	for (int i = 1; i <= N; i++) {
		int node = PQ.top();
		PQ.pop();

		res.push_back(node);

		for (int next : map[node]) {
			if (--degree[next] == 0) PQ.push(next);
		}
	}

	for (int i : res) cout << i << " ";

	delete[] degree;
}