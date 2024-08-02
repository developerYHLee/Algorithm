#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <memory.h>
#include <climits>

using namespace std;
typedef pair<int, int> pii;

struct Node {
	int row, col, cnt;

	Node(int row, int col, int cnt) : row(row), col(col), cnt(cnt) {}
};

int N, M, arr[50][50], res, dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
vector<pii> virus;
bool vis[50][50], vVis[300];

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		
			if (arr[i][j] == 2) virus.push_back({ i, j });
		}
	}
	res = INT_MAX;
}

bool checkVirus() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] != 1 && !vis[i][j]) return false;
		}
	}
	return true;
}

int bfs() {
	int ret = 0;
	queue<Node> Q;

	for (int i = 0; i < virus.size(); i++) {
		if (vVis[i]) {
			int row = virus[i].first, col = virus[i].second;
			Q.push(Node(row, col, 0));
			vis[row][col] = true;
		}
	}

	while (!Q.empty()) {
		Node node = Q.front();
		Q.pop();

		int row = node.row, col = node.col, cnt = node.cnt;

		ret = max(ret, cnt);
	
		for (int i = 0; i < 4; i++) {
			int r = row + dx[i];
			int c = col + dy[i];

			if (r < 0 || c < 0 || r >= N || c >= N || vis[r][c] || arr[r][c] == 1) continue;

			Q.push(Node(r, c, cnt + 1));
			vis[r][c] = true;
		}
	}

	if (checkVirus()) return ret;
	else return INT_MAX;
}

void recur(int index, int k) {
	if (k == M) {
		memset(vis, false, sizeof(vis));
		res = min(res, bfs());
		return;
	}
	if (index == virus.size()) return;

	vVis[index] = true;
	recur(index + 1, k + 1);
	vVis[index] = false;
	recur(index + 1, k);
}

void solve() {
	recur(0, 0);
	cout << (res == INT_MAX ? -1 : res);
}

int main() { //¿¬±¸¼Ò 2
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}