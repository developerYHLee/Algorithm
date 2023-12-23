#include <iostream>
#include <cmath>
#include <queue>
#include <memory.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

int N, M, dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 }, res;
bool land[50][50], vis[50][50];

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < M; j++) land[i][j] = str[j] == 'L' ? true : false;
	}
}

bool check(int row, int col) {
	if (row < 0 || col < 0 || row >= N || col >= M || !land[row][col] || vis[row][col]) return false;
	return true;
}

void bfs(int startRow, int startCol) {
	queue<piii> Q;

	Q.push({ { startRow, startCol }, 0 });
	vis[startRow][startCol] = true;

	while (!Q.empty()) {
		piii cur = Q.front();
		Q.pop();

		int row = cur.first.first, col = cur.first.second, cnt = cur.second;
		res = max(res, cnt);

		for (int i = 0; i < 4; i++) {
			int r = row + dx[i];
			int c = col + dy[i];

			if (!check(r, c)) continue;

			vis[r][c] = true;
			Q.push({ {r, c}, cnt + 1 });
		}
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!land[i][j]) continue;

			memset(vis, false, sizeof(vis));
			bfs(i, j);
		}
	}

	cout << res;
}

int main() { //º¸¹°¼¶
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}