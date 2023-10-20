#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

int parent[500000];

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

int main() { //사이클 게임
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) parent[i] = i;

	vector<pii> map(M);
	for (int i = 0; i < M; i++) {
		int o1, o2;
		cin >> o1 >> o2;

		map[i] = { o1, o2 };
	}

	for (int i = 0; i < map.size(); i++) {
		int o1 = map[i].first, o2 = map[i].second;

		if (!merge(o1, o2)) {
			cout << (i + 1);
			return 0;
		}
	}

	cout << 0;
}