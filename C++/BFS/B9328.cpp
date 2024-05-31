#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;
typedef pair<int, int> pii;
void openDoor(char k);

int N, M, dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 }, res;
char _map[100][100];
bool alpha[26], vis[100][100];
queue<pii> Q;

void input() {
	memset(alpha, false, sizeof(alpha));
	memset(vis, false, sizeof(vis));
	res = 0;
	Q = queue<pii>();

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> _map[i][j];
	}

	string str;
	cin >> str;

	if (str[0] != '0') {
		for (int i = 0; i < str.size(); i++) openDoor(str[i]);
	}
}

void openDoor(char k) {
	if (alpha[k - 97]) return;
	alpha[k - 97] = true;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (k - 32 == _map[i][j]) {
				_map[i][j] = '.';
				
				if(vis[i][j]) Q.push({ i, j });
			}
		}
	}
}

void checkRowCol(int row, int col) {
	if (row < 0 || col < 0 || row >= N || col >= M || vis[row][col] || _map[row][col] == '*') return;
	if (_map[row][col] >= 'A' && _map[row][col] <= 'Z') {
		vis[row][col] = true;
		return;
	}
	if (_map[row][col] >= 'a' && _map[row][col] <= 'z') {
		openDoor(_map[row][col]);
		_map[row][col] = '.';
	}

	Q.push({ row, col });
	vis[row][col] = true;

	return;
}

void enter() {
	for (int i = 0; i < M; i++) {
		checkRowCol(0, i);
		checkRowCol(N - 1, i);
	}

	for (int i = 0; i < N; i++) {
		checkRowCol(i, 0);
		checkRowCol(i, M - 1);
	}
}

void bfs() {
	while (!Q.empty()) {
		pii node = Q.front();
		Q.pop();

		int row = node.first, col = node.second;

		if (_map[row][col] == '$') {
			res++;
			_map[row][col] = '.';
		}

		for (int i = 0; i < 4; i++) {
			int r = row + dx[i];
			int c = col + dy[i];

			checkRowCol(r, c);
		}
	}
}

void solve() {
	enter();
	bfs();

	cout << res << "\n";
}

int main() { //¿­¼è
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T-- > 0) {
		input();
		solve();
	}
}