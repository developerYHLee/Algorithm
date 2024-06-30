#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

struct Node {
	int row, col, cnt;
	bool ch;

	Node(int row, int col, int cnt, bool ch) : row(row), col(col), cnt(cnt), ch(ch) {}
};

int N, M, dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
bool vis[1000][1000];
char _map[1000][1000];
queue<Node> Q;

void input() {
	memset(vis, false, sizeof(vis));
	Q = queue<Node>();

	cin >> M >> N;

	int row, col;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> _map[i][j];
		
			if (_map[i][j] == '*') {
				Q.push(Node(i, j, 0, false));
				vis[i][j] = true;
			}
			else if (_map[i][j] == '@') {
				row = i;
				col = j;
			}
		}
	}

	Q.push(Node(row, col, 0, true));
	vis[row][col] = true;
}

void solve() {
	while (!Q.empty()) {
		Node node = Q.front();
		Q.pop();

		int row = node.row, col = node.col, cnt = node.cnt;
		bool ch = node.ch;

		for (int i = 0; i < 4; i++) {
			int r = row + dx[i];
			int c = col + dy[i];

			if (r < 0 || c < 0 || r >= N || c >= M) {
				if (ch) {
					cout << cnt + 1 << "\n";
					return;
				}
				else continue;
			}

			if (vis[r][c] || _map[r][c] == '#') continue;
			vis[r][c] = true;

			Q.push(Node(r, c, cnt + 1, ch));
		}
	}

	cout << "IMPOSSIBLE\n";
}

int main() { //บา
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		input();
		solve();
	}
}