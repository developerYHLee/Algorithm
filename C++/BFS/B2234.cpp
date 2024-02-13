#include <iostream>
#include <queue>
#include <cmath>
#include <memory.h>

using namespace std;
typedef pair<int, int> pii;

int N, M, info[50][50], room[50][50], sz[2501], roomNum = 1, dx[4] = { 0, -1, 0, 1 }, dy[4] = { -1, 0, 1, 0 };
bool wall[4], vis[50][50], visRoomNum[2501];

void input() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> info[i][j];
	}
}

void get_wall(int num) {
	memset(wall, false, sizeof(wall));
	int p = 3;
	
	while (num) {
		int temp = 1 << p;

		if (num >= temp) {
			wall[p] = true;
			num -= temp;
		}
		p--;
	}
}

int bfs1(int startRow, int startCol) {
	int ret = 0;
	
	queue<pii> Q;
	Q.push({ startRow, startCol });
	vis[startRow][startCol] = true;

	while (!Q.empty()) {
		pii node = Q.front();
		Q.pop();

		int row = node.first, col = node.second;
		
		get_wall(info[row][col]);

		room[row][col] = roomNum;
		ret++;

		for (int i = 0; i < 4; i++) {
			if (wall[i]) continue;

			int r = row + dx[i];
			int c = col + dy[i];

			if (r < 0 || c < 0 || r >= N || c >= M || vis[r][c]) continue;
		
			Q.push({ r, c });
			vis[r][c] = true;
		}
	}

	return ret;
}

int bfs2(int startRow, int startCol) {
	memset(visRoomNum, false, sizeof(visRoomNum));

	int ret = sz[room[startRow][startCol]];
	
	queue<pii> Q;
	Q.push({ startRow, startCol });
	visRoomNum[room[startRow][startCol]] = true;
	vis[startRow][startCol] = true;

	while (!Q.empty()) {
		pii node = Q.front();
		Q.pop();

		int row = node.first, col = node.second;

		get_wall(info[row][col]);

		for (int i = 0; i < 4; i++) {
			int r = row + dx[i];
			int c = col + dy[i];

			if (wall[i]) {
				if (!visRoomNum[room[r][c]]) {
					ret = max(ret, sz[room[startRow][startCol]] + sz[room[r][c]]);
					visRoomNum[room[r][c]] = true;
				}
				continue;
			}

			if (r < 0 || c < 0 || r >= N || c >= M || vis[r][c]) continue;

			Q.push({ r, c });
			vis[r][c] = true;
		}
	}

	return ret;
}

void solve() {
	int roomCnt = 0, maxRoom1 = 0, maxRoom2 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (vis[i][j]) continue;

			sz[roomNum] = bfs1(i, j);
			maxRoom1 = max(maxRoom1, sz[roomNum++]);
			roomCnt++;
		}
	}

	memset(vis, false, sizeof(vis));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visRoomNum[room[i][j]]) continue;

			maxRoom2 = max(maxRoom2, bfs2(i, j));
		}
	}

	cout << roomCnt << "\n" << maxRoom1 << "\n" << maxRoom2;
}

int main() { //¼º°û
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}