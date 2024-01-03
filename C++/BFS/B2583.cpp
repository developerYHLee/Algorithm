#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int N, M, K, dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
bool box[100][100];

void fill_map(int x1, int y1, int x2, int y2) {
	for (int i = y1; i < y2; i++) {
		for (int j = x1; j < x2; j++) box[i][j] = true;
	}
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		fill_map(x1, y1, x2, y2);
	}
}

bool check(int row, int col) {
	if (row < 0 || col < 0 || row >= N || col >= M || box[row][col]) return false;
	return true;
}

int bfs(int startRow, int startCol) {
	int ret = 0; 
	queue<pii> Q;
	Q.push({ startRow, startCol });
	box[startRow][startCol] = true;

	while (!Q.empty()) {
		pii node = Q.front();
		Q.pop();
		
		int row = node.first, col = node.second;

		ret++;
		for (int i = 0; i < 4; i++) {
			int r = row + dx[i];
			int c = col + dy[i];

			if (!check(r, c)) continue;

			Q.push({ r, c });
			box[r][c] = true;
		}
	}

	return ret;
}

void solve() {
	priority_queue<int, vector<int>, greater<int>> PQ;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!box[i][j]) PQ.push(bfs(i, j));
		}
	}

	cout << PQ.size() << '\n';
	while (!PQ.empty()) {
		int res = PQ.top();
		PQ.pop();

		cout << res << " ";
	}
}

int main() { //영역 구하기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}