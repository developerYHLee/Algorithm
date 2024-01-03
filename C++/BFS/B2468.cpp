#include <iostream>
#include <cmath>
#include <queue>
#include <memory.h>

using namespace std;
typedef pair<int, int> pii;

int N, area[100][100], res, dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };;
bool vis[100][100];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> area[i][j];
	}
}

bool check(int row, int col, int h) {
	if (row < 0 || col < 0 || row >= N || col >= N || area[row][col] <= h || vis[row][col]) return false;
	return true;
}

void bfs(int startRow, int startCol, int h) {
	queue<pii> Q;
	Q.push({ startRow, startCol });
	vis[startRow][startCol] = true;

	while (!Q.empty()) {
		pii node = Q.front();
		Q.pop();

		int row = node.first, col = node.second;
		for (int i = 0; i < 4; i++) {
			int r = row + dx[i];
			int c = col + dy[i];

			if (!check(r, c, h)) continue;

			Q.push({ r, c });
			vis[r][c] = true;
		}
	}
}

void solve() {
	for (int i = 0; i <= 100; i++) {
		memset(vis, false, sizeof(vis));
		int temp = 0;

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (area[j][k] <= i || vis[j][k]) continue;

				bfs(j, k, i);				
				temp++;
			}
		}

		res = max(res, temp);
	}

	cout << res;
}

int main() { //안전 영역
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}