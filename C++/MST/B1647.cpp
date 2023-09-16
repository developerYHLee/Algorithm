#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	int s, e, c;

	Edge(int start, int end, int cost) : s(start), e(end), c(cost) {}
	bool operator <(const Edge& o) { return c < o.c; }
};
//bool comp(vector<int> o1, vector<int> o2) { return o1[2] < o2[2]; }

bool check;
int parent[100001];

int find(int x) {
	if (parent[x] < 0) return x;

	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	int x = find(a);
	int y = find(b);

	check = false;
	if (x == y) return;

	check = true;
	if (x > y) parent[y] = x;
	else parent[x] = y;
}

int main() { //도시 분할 계획
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<Edge> map;
	for (int i = 0; i < M; i++) {
		int A, B, C;

		cin >> A >> B >> C;
		map.push_back(Edge(A, B, C));
	}

	sort(map.begin(), map.end());

	fill_n(parent, N, -1);

	int cut = 0, res = 0;
	for (int i = 0; i < M; i++) {
		merge(map[i].s, map[i].e);

		if (check) {
			res += map[i].c;
			cut = max(cut, map[i].c);
		}
	}

	cout << res - cut;
}