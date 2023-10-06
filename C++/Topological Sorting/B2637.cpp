#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int degree[101], res[101];
vector<vector<pii>> map;

void topological_sorting(int N) {
	queue<int> Q;
	Q.push(N);
	res[N] = 1;

	while (!Q.empty()) {
		int prev = Q.front();
		Q.pop();

		for (pii next : map[prev]) {
			int node = next.first, count = next.second;

			res[node] += res[prev] * count;
			if (--degree[node] == 0) Q.push(node);
		}
	}
}

int main() { //장난감 조립
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	map.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int X, Y, K;
		cin >> X >> Y >> K;

		degree[Y]++;
		map[X].push_back({ Y, K });
	}

	topological_sorting(N);
	for (int i = 1; i < N; i++) {
		if (map[i].size() == 0) cout << i << " " << res[i] << "\n";
	}
}