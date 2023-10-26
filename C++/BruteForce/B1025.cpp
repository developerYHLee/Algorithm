#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int map[10][10], N, M;
ll res = -1;

inline bool check(ll num) {
	ll s = (ll)sqrt(num);
	return s * s == num;
}

void start_solve(int row, int col, int i, int j) {
	ll num = map[row][col];
	if (i == 0 && j == 0) {
		if (check(num)) res = max(res, num);
		return;
	}

	for (int k = 1; k <= 9; k++) {
		int r = row + k * i;
		int c = col + k * j;

		if (r < 0 || c < 0 || r >= N || c >= M) {
			return;
		}

		num = num * (ll)10 + map[r][c];
		if (check(num)) res = max(res, num);
	}
}

void solve(int row, int col) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			start_solve(row, col, i, j);
			start_solve(row, col, -i, j);
			start_solve(row, col, i, -j);
			start_solve(row, col, -i, -j);
		}
	}
}

int main() { //Á¦°ö¼ö Ã£±â
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < M; j++) map[i][j] = str[j] - '0';
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) solve(i, j);
	}

	cout << res;
}