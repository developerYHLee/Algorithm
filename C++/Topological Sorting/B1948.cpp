#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int degree[10001], cost[10001];
bool vis[10001];
vector<vector<pair<int, int> > > map;
vector<vector<int> > map_reverse;

int check_bridge(int N, int E) {
	memset(vis, false, (N + 1) * sizeof(bool));

	int bridge = 0;
	queue<int> Q;
	Q.push(E);

	while (!Q.empty()) {
		int prev = Q.front();
		Q.pop();

		for (int next : map_reverse[prev]) {
			bridge++;

			if (vis[next]) continue;
			vis[next] = true;
			
			Q.push(next);
		}
	}

	return bridge;
}

void topological_sorting(int S) {
	queue<int> Q;
	Q.push(S);

	while (!Q.empty()) {
		int prev = Q.front();
		Q.pop();

		for (const pair<int, int>& next : map[prev]) {
			int n = next.first, c = next.second;

			if (cost[n] <= cost[prev] + c) {
				if (cost[n] == cost[prev] + c) map_reverse[n].push_back(prev);
				else {
					map_reverse[n].clear();
					map_reverse[n].push_back(prev);
				}

				cost[n] = cost[prev] + c;
			}
			if (--degree[n] == 0) Q.push(n);
		}
	}
}

void make_degree(int S) {
	queue<int> Q;
	
	Q.push(S);
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		
		for (const pair<int, int>& next : map[cur]) {
			degree[next.first]++;
			
			if (vis[next.first]) continue;
			
			Q.push(next.first);
			vis[next.first] = true;
		}
	}
}

void initiate(int N, int M) {
	map.resize(N + 2);
	map_reverse.resize(N + 2);
	for (int i = 0; i < M; i++) {
		int s, e, c;

		cin >> s >> e >> c;
		map[s].push_back({ e, c });
	}
}

int main() { //임계경로
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	initiate(N, M);

	int S, E;
	cin >> S >> E;
	make_degree(S);

	topological_sorting(S);

	cout << cost[E] << "\n" << check_bridge(N, E);
}