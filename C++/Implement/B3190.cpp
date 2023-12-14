#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, char> pic;
typedef pair<int, int> pii;

int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, -1, 0, 1 }, N;
bool apple[100][100], snake_body[100][100];
queue<pic> rot;

void input() {
	cin >> N;

	int K;
	cin >> K;

	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> r >> c;

		apple[r - 1][c - 1] = true;
	}

	int L;
	cin >> L;

	for (int i = 0; i < L; i++) {
		int X;
		char C;
		cin >> X >> C;

		rot.push({ X, C });
	}
}

bool check(int row, int col) {
	if (row < 0 || col < 0 || row >= N || col >= N || snake_body[row][col]) return false;
	return true;
}

int solve() {
	queue<pii> Q;
	
	int row = 0, col = 0, dir = 3, ret = 0;
	Q.push({ 0, 0 });
	snake_body[0][0] = true;

	while (true) {
		if (!rot.empty()) {
			pic node = rot.front();
			int X = node.first, C = node.second;
			
			if (X == ret) {
				rot.pop();

				if (C == 'L') dir++;
				else if (C == 'D') dir += 3;

				dir %= 4;
			}
		}

		ret++;
		row += dx[dir];
		col += dy[dir];
		Q.push({ row, col });

		if (!check(row, col)) return ret;

		snake_body[row][col] = true;
		if (apple[row][col]) apple[row][col] = false;
		else {
			pii node = Q.front();
			Q.pop();

			snake_body[node.first][node.second] = false;
		}
	}

	return -1;
}

int main() { //¹ì
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	cout << solve();
}