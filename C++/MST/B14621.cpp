#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int d, s, e;

	Node(int d, int s, int e) : d(d), s(s), e(e) {}
};

vector<Node> map;
bool isM[1001];
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

int main() { //나만 안되는 연애
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		char c;
		cin >> c;

		parent[i] = i;
		isM[i] = c == 'M' ? true : false;
	}

	for (int i = 0; i < M; i++) {
		int s, e, d;

		cin >> s >> e >> d;

		if (!(isM[s] ^ isM[e])) continue;

		map.push_back(Node(d, s, e));
	}

	sort(map.begin(), map.end(), [](Node o1, Node o2) { return o1.d < o2.d; });

	int sum = 0, count = 0;
	for (const Node& cur : map) {
		int s = cur.s, e = cur.e, d = cur.d;

		if (merge(s, e)) {
			sum += d;
			count++;
		}
	}

	cout << ((count == N - 1) ? sum : -1);
}