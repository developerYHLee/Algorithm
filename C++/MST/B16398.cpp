#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, pair<int, int>> pii;

bool vis[1001][1001];
int parent[1001];

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

bool merge(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (x == y) return false;
	if (x > y) parent[x] = y;
	else parent[y] = x;

	return true;
}

int main() { //행성 연결
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<pii> map;
	for (int i = 0; i < N; i++) {
		parent[i] = i;
		for (int j = 0; j < N; j++) {
			int d;
			cin >> d;

			if (i == j || vis[i][j]) continue;
			
			map.push_back({ d, {i, j} });
			vis[i][j] = true;
			vis[j][i] = true;
		}
	}

	sort(map.begin(), map.end());

	ll sum = 0;
	for (int i = 0; i < map.size(); i++) {
		int x = map[i].second.first, y = map[i].second.second;

		if (merge(x, y)) sum += map[i].first;
	}

	cout << sum;
}