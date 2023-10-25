#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


struct Node {
	int cost, row, col;

	void make_node(int _cost, int _row, int _col) {
		cost = _cost;
		row = _row;
		col = _col;
	}
};

int cmp(Node o1, Node o2) {
	return o1.cost < o2.cost;
}

Node map[2501];
int parent[51];

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

bool merge(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (x == y) return false;

	if (x < y) parent[y] = x;
	else parent[x] = y;

	return true;
}

int main() { //ºÒ¿ìÀÌ¿ôµ½±â
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	cin.ignore();

	for (int i = 0; i < N; i++) {
		parent[i + 1] = i + 1;
		
		string str;
		getline(cin, str);
		for (int j = 1; j <= N; j++) {
			if (str[j - 1] == '0') map[i * N + j].make_node(0, i + 1, j);
			else if (str[j - 1] >= 'a' && str[j - 1] <= 'z') map[i * N + j].make_node(str[j - 1] - 'a' + 1, i + 1, j);
			else map[i * N + j].make_node(str[j - 1] - 'A' + 27, i + 1, j);
		}
	}
	sort(map, map + N * N + 1, cmp);

	int res = 0;
	for (int i = 1; i <= N * N; i++) {
		int cost = map[i].cost, row = map[i].row, col = map[i].col;

		if (!cost) continue;
		if (!merge(row, col)) res += cost;
		
	}

	int x = find(1);
	for (int i = 2; i <= N; i++) {
		if (x != find(i)) {
			cout << -1;
			return 0;
		}
	}

	cout << res;
}