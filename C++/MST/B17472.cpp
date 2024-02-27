#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;
typedef pair<int, int> pii;

struct Node {
	int row, col, cnt, dir, p;

	Node(int row, int col, int cnt, int dir, int p) : row(row), col(col), cnt(cnt), dir(dir), p(p) {}

	bool operator<(Node o) const { return cnt > o.cnt; }
};

int N, M, res, startRow, startCol, dx[4] = { 1, 0 , -1, 0 }, dy[4] = { 0, 1, 0, -1 }, land[10][10], parent[101], pIndex;
bool bridge[10][10], visDir[10][10][2], vis[10][10];
priority_queue<Node> PQ;

void printParent() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << parent[land[i][j]] << " ";
		}
		cout << "\n";
	}
}

void checkParent(int sRow, int sCol) {
	queue<pii> Q;
	Q.push({ sRow, sCol });
	vis[sRow][sCol] = true;

	pIndex++;
	land[sRow][sCol] = pIndex;

	while (!Q.empty()) {
		pii node = Q.front();
		Q.pop();

		int row = node.first, col = node.second;
		for (int i = 0; i < 4; i++) {
			int r = row + dx[i];
			int c = col + dy[i];

			if (r < 0 || c < 0 || r >= N || c >= M || vis[r][c] || !bridge[r][c]) continue;

			Q.push({ r, c });
			vis[r][c] = true;
			land[r][c] = pIndex;
		}
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> bridge[i][j];
			if (bridge[i][j]) {
				startRow = i;
				startCol = j;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (bridge[i][j] && !land[i][j]) {
				checkParent(i, j);
				parent[pIndex] = pIndex;
			}
		}
	}

	memset(vis, false, sizeof(vis));
}

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	int x = find(a);
	int y = find(b);

	parent[x] = y;
}

void insertPQ(int sRow, int sCol) {
	queue<pii> Q;
	Q.push({ sRow, sCol });
	vis[sRow][sCol] = true;

	while (!Q.empty()) {
		pii node = Q.front();
		Q.pop();

		int row = node.first, col = node.second;
		for (int i = 0; i < 4; i++) {
			int r = row + dx[i];
			int c = col + dy[i];

			if (r < 0 || c < 0 || r >= N || c >= M || vis[r][c]) continue;
			
			//if bridge[row][col] is Land
			if (bridge[r][c]) {
				Q.push({ r, c });
				vis[r][c] = true;
			}
			else {
				PQ.push(Node(r, c, 1, i, land[row][col]));
				visDir[r][c][i % 2] = true;
			}
		}
	}
}

void solve() {
	insertPQ(startRow, startCol);
	
	while (!PQ.empty()) {
		Node node = PQ.top();
		PQ.pop();

		int row = node.row, col = node.col, cnt = node.cnt, dir = node.dir, p = node.p;

		row += dx[dir];
		col += dy[dir];

		if (row < 0 || col < 0 || row >= N || col >= M || visDir[row][col][dir % 2] || find(land[row][col]) == find(p)) continue;

		//if bridge[row][col] is Land
		if (bridge[row][col]) {
			if (cnt < 2) continue;
			
			res += cnt;
			merge(p, land[row][col]);
			insertPQ(row, col);
		}
		else {
			PQ.push(Node(row, col, cnt + 1, dir, p));
			visDir[row][col][dir % 2] = true;
		}
	}

	int p = find(land[startRow][startCol]);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (bridge[i][j] && p != find(land[i][j])) {
				cout << -1;
				return;
			}
		}
	}

	cout << res;
}

int main() { //다리 만들기 2
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}