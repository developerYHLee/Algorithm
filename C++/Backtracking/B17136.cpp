#include <iostream>
#include <cmath>
#include <climits>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

int board[10][10], cnt[6], res;
bool vis[10][10];

void input() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) cin >> board[i][j];
	}

	for (int i = 1; i <= 5; i++) cnt[i] = 5;
	res = INT_MAX;
}

void recur(int row, int col, int sum) {
	if (row == 10) {
		res = min(res, sum);
		return;
	}

	if (res <= sum) return;

	if (col >= 10) {
		recur(row + 1, 0, sum);
		return;
	}

	if (!board[row][col] || vis[row][col]) {
		recur(row, col + 1, sum);
		return;
	}

	vector<pii> temp;

	for (int i = 5; i > 0; i--) {
		if (!cnt[i]) continue;

		int r = row + i - 1, c = col + i - 1;

		if (r >= 10 || c >= 10) continue;

		bool ch = false;
		temp.clear();

		for (int j = row; j <= r; j++) {
			for (int k = col; k <= c; k++) {
				if (!board[j][k] || vis[j][k]) {
					ch = true;
					break;
				}

				temp.push_back({ j, k });
			}

			if (ch) break;
		}

		if (!ch) {
			cnt[i]--;

			for (pii p : temp) {
				int tempRow = p.first, tempCol = p.second;

				vis[tempRow][tempCol] = true;
			}

			recur(row, c + 1, sum + 1);

			cnt[i]++;
			for (pii p : temp) {
				int tempRow = p.first, tempCol = p.second;

				vis[tempRow][tempCol] = false;
			}
		}
	}
}

void solve() {
	recur(0, 0, 0);
	cout << (res == INT_MAX ? -1 : res);
}

int main() { //색종이 붙이기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}