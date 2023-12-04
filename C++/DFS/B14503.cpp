#include <iostream>

using namespace std;

int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 }, N, M, s_r, s_c, s_d, res;
bool wall[50][50], vis[50][50];

void input() {
	cin >> N >> M >> s_r >> s_c >> s_d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> wall[i][j];
	}
}

bool check(int row, int col) {
	if (row < 0 || col < 0 || row >= N || col >= M || wall[row][col]) return false;
	return true;
}

void dfs(int row, int col, int dir) {
	if (!vis[row][col]) res++;
	vis[row][col] = true;

	int d = dir;
	for (int i = 0; i < 4; i++) {
		d = (d + 3) % 4;
		int r = row + dx[d];
		int c = col + dy[d];

		if (check(r, c) && !vis[r][c]) {
			dfs(r, c, d);
			return;
		}
	}

	int r = row - dx[dir], c = col - dy[dir];
	if (check(r, c)) dfs(r, c, dir);
}

int main() { //·Îº¿ Ã»¼Ò±â
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	dfs(s_r, s_c, s_d);
	cout << res;
}