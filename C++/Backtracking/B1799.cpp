#include <iostream>
#include <cmath>

using namespace std;

bool board[10][10], map[10][10], p[20], m[20];
int w_cnt, b_cnt, N;

void initiate() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int index = i;

		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			board[i][j] = index++ % 2;
		}
	}
}

void search(int row, int col, int cnt, bool color) {
	if (row == N) {
		if (color) b_cnt = max(b_cnt, cnt);
		else w_cnt = max(w_cnt, cnt);

		return;
	}

	if (col >= N) {
		search(row + 1, 0, cnt, color);
		return;
	}

	if (board[row][col] != color) {
		search(row, 1, cnt, color);
		return;
	}

	int p_i = row + col, m_i = row + N - col - 1;

	if (!map[row][col] || p[p_i] || m[m_i]) {
		search(row, col + 2, cnt, color);
		return;
	}

	p[p_i] = true;
	m[m_i] = true;
	search(row, col + 2, cnt + 1, color);
	p[p_i] = false;
	m[m_i] = false;
	search(row, col + 2, cnt, color);
}

int main() { //ºñ¼ó
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	initiate();
	search(0, 0, 0, 0);
	search(0, 1, 0, 1);

	cout << (w_cnt + b_cnt);
}