#include <iostream>
#include <queue>
#include <cmath>
#include <memory.h>

using namespace std;

int N, M, t, cnt_c, cheese[100][100], cnt[100][100], dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
bool vis[100][100];

void input() {
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> cheese[i][j];
	}
}

bool search_cheese() {
	bool ret = false;

	queue<pair<int, int>> Q;
	memset(vis, false, sizeof(vis));

	Q.push({ 0 ,0 });
	vis[0][0] = true;
	t++;

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();

		int row = cur.first, col = cur.second;

		for (int i = 0; i < 4; i++) {
			int r = row + dx[i];
			int c = col + dy[i];

			if (r < 0 || c < 0 || r >= N || c >= M || vis[r][c]) continue;
			
			vis[r][c] = true;
			if (cheese[r][c]) {
				cheese[r][c] = 0;
				cnt[r][c] = t;
				ret = true;
			}
			else Q.push({ r, c });
		}
	}

	return ret;
}

void bfs(int startR, int startC) {
	queue<pair<int, int>> Q;
	Q.push({ startR, startC });
	vis[startR][startC] = true;

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();

		int row = cur.first, col = cur.second;
		cnt_c++;

		for (int i = 0; i < 4; i++) {
			int r = row + dx[i];
			int c = col + dy[i];

			if (r < 0 || c < 0 || r >= N || c >= M || vis[r][c] || cnt[r][c] != t) continue;

			Q.push({ r, c });
			vis[r][c] = true;
		}
	}
}

void solve() {
	while (search_cheese());
	memset(vis, false, sizeof(vis));
	t--;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (cnt[i][j] == t && !vis[i][j]) bfs(i, j);
		}
	}

	cout << t << "\n" << cnt_c;
}

int main() { //ДЎБо
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}