#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
	double t, s;
	int row, col;

	Node(double _t, double _s, int _row, int _col) : t(_t), s(_s), row(_row), col(_col) {};

	bool operator<(const Node& o) const { return  t > o.t; }
};

int V, R, C;
double dis[100][100];
int map[100][100], dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
priority_queue<Node> PQ;

void solve() {
	PQ.push(Node(0, V, 0, 0));

	while (!PQ.empty()) {
		Node cur = PQ.top();
		PQ.pop();

		int row = cur.row, col = cur.col;
		double t = cur.t, s = cur.s;
		
		if (t > dis[row][col]) continue;
		
		for (int i = 0; i < 4; i++) {
			int r = row + dx[i];
			int c = col + dy[i];

			if (r < 0 || c < 0 || r >= R || c >= C) continue;

			int h = map[row][col], next_h = map[r][c];
			double next_t = t + 1 / s, next_s = s * pow(2, h - next_h);
			
			if (dis[r][c] > next_t) {
				dis[r][c] = next_t;
				PQ.push(Node(next_t, next_s, r, c));
			}

		}
	}
}

int main() { //»ê¾ÇÀÚÀü°Å
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) cin >> map[i][j];
	}
	for (int i = 0; i < R; i++) fill_n(dis[i], C, pow(2, 51));
	
	solve();
	cout << fixed;
	cout.precision(2);
	cout << dis[R - 1][C - 1];
}