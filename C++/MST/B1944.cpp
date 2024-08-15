#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

struct Node {
	int row, col, dis;

	Node(int r, int c, int d) : row(r), col(c), dis(d) {}
};

int N, M, dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 }, parent[251];
bool vis[50][50];
char maze[50][50];
unordered_map<int, int> nodeKey;
unordered_set<string> visNode;
vector<piii> E;

int convertRowCol(int row, int col) {
	return row * N + col;
}

void input() {
	cin >> N >> M;

	int key = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == 'S' || maze[i][j] == 'K') nodeKey.insert({ convertRowCol(i, j), key++ });
		}
	}

	for (int i = 0; i <= M; i++) parent[i] = -1;
}

void bfs(int startNode) {
	memset(vis, false, sizeof(vis));
	int startNodeKey = nodeKey[startNode], startRow = startNode / N, startCol = startNode % N;

	queue<Node> Q;
	Q.push(Node(startRow, startCol, 0));
	vis[startRow][startCol] = true;

	while (!Q.empty()) {
		Node node = Q.front();
		Q.pop();

		int row = node.row, col = node.col, dis = node.dis;

		for (int i = 0; i < 4; i++) {
			int r = row + dx[i];
			int c = col + dy[i];

			if (r < 0 || c < 0 || r >= N || c >= N || vis[r][c] || maze[r][c] == '1') continue;

			Q.push(Node(r, c, dis + 1));
			vis[r][c] = true;

			if (maze[r][c] == 'S' || maze[r][c] == 'K') {
				int nextNodeKey = nodeKey[convertRowCol(r, c)], tempKey = startNodeKey;

				if (tempKey > nextNodeKey) swap(tempKey, nextNodeKey);

				string key = to_string(tempKey) + " " + to_string(nextNodeKey);

				if (visNode.find(key) == visNode.end()) {
					visNode.insert(key);
					E.push_back({ dis + 1, { tempKey, nextNodeKey } });
				}
			}
		}
	}
}

void makeEdge() {
	for (auto iter : nodeKey) bfs(iter.first);
}

int find(int x) {
	if (parent[x] == -1) return x;
	return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) return false;

	parent[x] = y;
	return true;
}

int mst() {
	int ret = 0;
	for (const piii& e : E) {
		int dis = e.first, x = e.second.first, y = e.second.second;

		if (merge(x, y)) ret += dis;
	}

	int x = find(0);
	for (int i = 1; i <= M; i++) {
		if (x != find(i)) return -1;
	}

	return ret;
}

void solve() {
	makeEdge();
	sort(E.begin(), E.end());
	cout << mst();
}

int main() { //º¹Á¦ ·Îº¿
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}