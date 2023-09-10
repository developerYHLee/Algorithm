#include <iostream>

using namespace std;

void solve(int, int, int);

char map[21][21];
bool vis[26];
int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
int _count = 0, R, C;

int main() { //¾ËÆÄºª
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) cin >> map[i][j];
	}

	int index = map[0][0] - 'A';
	vis[index] = true;
	solve(0, 0, 1);

	cout << _count;
}

void solve(int row, int col, int x) {
	_count = max(_count, x);

	for (int i = 0; i < 4; i++) {
		int r = row + dx[i];
		int c = col + dy[i];

		if (r < 0 || c < 0 || r >= R || c >= C) continue;

		int index = map[r][c] - 'A';
		if (vis[index]) continue;

		vis[index] = true;
		solve(r, c, x + 1);
		vis[index] = false;
	}
}