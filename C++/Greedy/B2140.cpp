#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int N, dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
char board[100][100];

bool check(int row, int col) {
	for (int i = 0; i < 8; i++) {
		int r = row + dx[i];
		int c = col + dy[i];

		if (r < 0 || c < 0 || r >= N || c >= N) continue;
		if (board[r][c] == '0') return false;
	}

	return true;
}

void bomb(int row, int col) {
	for (int i = 0; i < 8; i++) {
		int r = row + dx[i];
		int c = col + dy[i];

		if (r < 0 || c < 0 || r >= N || c >= N) continue;
		if (board[r][c] != '#') board[r][c]--;
	}
}

int main() { //Áö·ÚÃ£±â
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	queue<pii> Q;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < N; j++) {
			board[i][j] = str[j];
			
			if (board[i][j] == '#') Q.push({ i, j });
		}
	}

	int res = 0;
	while (!Q.empty()) {
		pii cur = Q.front();
		Q.pop();

		int row = cur.first, col = cur.second;

		if (check(row, col)) {
			res++;
			bomb(row, col);
		}
	}

	cout << res;
}