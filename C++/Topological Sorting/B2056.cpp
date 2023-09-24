#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

queue<int> Q;
vector<vector<int>> map;
int degree[10001], cost[10001], res[10001];
int main() { //ÀÛ¾÷
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	map.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];

		int M;
		cin >> M;
		for (int j = 0; j < M; j++) {
			int node;
			cin >> node;

			map[node].push_back(i);
			degree[i]++;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) {
			Q.push(i);
			res[i] = cost[i];
		}
	}
	
	for (int i = 1; i <= N; i++) {
		int prev = Q.front();
		Q.pop();

		for (int next : map[prev]) {
			res[next] = max(res[next], res[prev] + cost[next]);
			if (--degree[next] == 0) Q.push(next);
		}
	}

	int m = 0;
	for (int i = 1; i <= N; i++) m = max(m, res[i]);
	
	cout << m;
}