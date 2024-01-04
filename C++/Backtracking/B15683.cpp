#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int N, M, _map[8][8], dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 }, cctv_sz, res = 1e9, total;
int vis[8][8];
vector<pii> cctv;

bool check(int row, int col, bool p) {
	if (row < 0 || col < 0 || row >= N || col >= M || (_map[row][col] > 0 && _map[row][col] < 6)) return false;
	return true;
}

void one(int row, int col, int d_i, bool p) {
	d_i %= 4;

	for (int i = 1; i < 8; i++) {
		int r = row + dx[d_i] * i;
		int c = col + dy[d_i] * i;
		int ch = check(r, c, p);
		
		if (!ch) continue;
		if (_map[r][c] == 6) return;

		if (p) {
			vis[r][c]++;
			if (vis[r][c] == 1) total++;
		}
		else {
			vis[r][c]--;
			if (!vis[r][c]) total--;
		}
	}
}

void two(int row, int col, int d_i, bool p) {
	one(row, col, d_i, p);
	one(row, col, d_i + 2, p);
}

void three(int row, int col, int d_i, bool p) {
	one(row, col, d_i, p);
	one(row, col, d_i + 1, p);
}

void four(int row, int col, int d_i, bool p) {
	one(row, col, d_i, p);
	one(row, col, d_i + 1, p);
	one(row, col, d_i + 2, p);
}

void five(int row, int col, int d_i, bool p) {
	one(row, col, d_i, p);
	one(row, col, d_i + 1, p);
	one(row, col, d_i + 2, p);
	one(row, col, d_i + 3, p);
}

void set_cctv(int v_i, int d_i, bool p) {
	int row = cctv[v_i].first;
	int col = cctv[v_i].second;
	int n = _map[row][col];

	switch (n)
	{
	case 1:
		one(row, col, d_i, p);
		break;
	case 2:
		two(row, col, d_i, p);
		break;
	case 3:
		three(row, col, d_i, p);
		break;
	case 4:
		four(row, col, d_i, p);
		break;
	case 5:
		five(row, col, d_i, p);
		break;
	}
}

void solve(int v_i) {
	if (v_i == cctv_sz) {
		res = min(res, N * M - total);
		return;
	}

	for (int d_i = 0; d_i < 4; d_i++) {
		set_cctv(v_i, d_i, true);
		solve(v_i + 1);
		set_cctv(v_i, d_i, false);
	}
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> _map[i][j];
		
			if (_map[i][j] > 0 && _map[i][j] < 6) cctv.push_back({ i, j });
			else if (_map[i][j] == 6) total++;
		}
	}

	cctv_sz = cctv.size();
	total += cctv_sz;
}

int main() { //°¨½Ã
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve(0);
	cout << res;
}