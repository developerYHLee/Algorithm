#include <iostream>

using namespace std;

int N, M, dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
char board[50][50];
bool vis[50][50];

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> board[i][j];
	}
}

bool dfs(char color, int row, int col, int prevRow, int prevCol) {
	vis[row][col] = true;

	for (int i = 0; i < 4; i++) {
		int r = row + dx[i];
		int c = col + dy[i];

		if (r < 0 || c < 0 || r >= N || c >= M || color != board[r][c]) continue;
	
		if (vis[r][c]) {
			if (r != prevRow || c != prevCol) return true;
			continue;
		}

		if (dfs(color, r, c, row, col)) return true;
	}
	
	return false;
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (vis[i][j]) continue;

			if (dfs(board[i][j], i, j, i, j)) {
				cout << "Yes";
				return;
			}
		}
	}

	cout << "No";
}

int main() { //Two Dots
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}