#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> PQ;
int parent[10001];
bool check;

bool comp(vector<int> o1, vector<int> o2) { return o1[2] < o2[2]; }

int find(int x) {
	if (x == parent[x]) return x;

	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	int x = find(a);
	int y = find(b);
	
	check = false;

	if (x == y) return;

	parent[x] = y;
	check = true;
}

int main() { //최소 스패닝 트리
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;
	cin >> V >> E;
	
	for (int i = 1; i <= V; i++) parent[i] = i;

	vector<vector<int>> map;
	int res = 0;
	for (int i = 0; i < E; i++) {
		int A, B, C;

		cin >> A >> B >> C;
		map.push_back({ A, B, C });
	}

	sort(map.begin(), map.end(), comp);
	for (int i = 0; i < E; i++) {
		merge(map[i][0], map[i][1]);

		if (check) res += map[i][2];
	}

	cout << res;

	return 0;
}