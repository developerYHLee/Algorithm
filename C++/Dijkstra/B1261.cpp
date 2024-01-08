#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

struct Node {
	int row, col, cnt;

	Node(int row, int col, int cnt) : row(row), col(col), cnt(cnt) {}
};

int N, M, dis[100][100], dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
bool wall[100][100];

void input() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < M; j++) wall[i][j] = str[j] == '1' ? true : false;
	}

	for(int i = 0; i < N; i++) fill_n(dis[i], M, 1e9);
}

void bfs() {
	int res = 0;
	queue<pii> Q;
	Q.push({ 0, 0 });
	dis[0][0] = 0;

	while (!Q.empty()) {
		pii node = Q.front();
		Q.pop();

		int row = node.first, col = node.second;

		for (int i = 0; i < 4; i++) {
			int r = row + dx[i];
			int c = col + dy[i];

			if (r < 0 || c < 0 || r >= N || c >= M) continue;
			
			if (wall[r][c] && dis[r][c] > dis[row][col] + 1) {
				dis[r][c] = dis[row][col] + 1;
				Q.push({ r, c });
			}
			else if (!wall[r][c] && dis[r][c] > dis[row][col]) {
				dis[r][c] = dis[row][col];
				Q.push({ r, c });
			}
		}
	}

	cout << dis[N - 1][M - 1];
}

int main() { //¾Ë°í½ºÆÌ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	bfs();
}