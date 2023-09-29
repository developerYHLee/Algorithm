#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > map;
int res[1001], degree[1001];

void initiate(int N, int M) {
	map.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;

		map[s].push_back(e);
		degree[e]++;
	}
}

void topological_sorting(int N) {
	queue<int> Q;

	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) {
			Q.push(i);
			res[i] = 1;
		}
	}

	for (int i = 0; i < N; i++) {
		int prev = Q.front();
		Q.pop();

		for (int next : map[prev]) {
			if (--degree[next] == 0) {
				Q.push(next);
				res[next] = res[prev] + 1;
			}
		}
	}
}

int main() { //선수과목 (Prerequisite)
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	initiate(N, M);
	topological_sorting(N);

	for (int i = 1; i <= N; i++) cout << res[i] << " ";
}