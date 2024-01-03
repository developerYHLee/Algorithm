#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct Node {
	char name;
	int row, col, cnt;

	Node(char name, int row, int col, int cnt) : name(name), row(row), col(col), cnt(cnt) {}
};

int N, M, dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
char _map[50][50];
queue<Node> Q;

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < M; j++) _map[i][j] = str[j];
	}
}

bool check(int row, int col) {
	if (row < 0 || col < 0 || row >= N || col >= M || _map[row][col] == 'S' || _map[row][col] == '*' || _map[row][col] == 'X') return false;
	return true;
}

string bfs() {
	while (!Q.empty()) {
		Node node = Q.front();
		Q.pop();

		char name = node.name;
		int row = node.row, col = node.col, cnt = node.cnt;

		for (int i = 0; i < 4; i++) {
			int r = row + dx[i];
			int c = col + dy[i];

			if (!check(r, c)) continue;

			if (_map[r][c] == 'D') {
				if (name == 'S') return to_string(cnt + 1);
				else continue;
			}

			Q.push(Node(name, r, c, cnt + 1));
			_map[r][c] = name;
		}
	}

	return "KAKTUS";
}

void solve() {
	int row = -1, col = -1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (_map[i][j] == 'S') {
				row = i;
				col = j;
			}
			else if (_map[i][j] == '*') Q.push(Node('*', i, j, 0));
		}
	}

	Q.push(Node('S', row, col, 0));
	cout << bfs();
}

int main() { //Å»Ãâ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}