#include <iostream>
#include <cmath>

using namespace std;

int res = 1, N, M;
int map[51][51], dx[3] = { 1, 0, 1 }, dy[3] = { 0, 1, 1 };

void solve(int row, int col, int key) {
	for (int i = 1; i < 50; i++) {
		bool check = true;
		for (int j = 0; j < 3; j++) {
			int r = row + dx[j] * i, c = col + dy[j] * i;

			if (r >= N || c >= M) return;
			if (map[r][c] != key) {
				check = false;
				break;
			}
		}

		if (check) res = max(res, i + 1);
	}
	
}

int main() { //숫자 정사각형
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < M; j++) map[i][j] = str[j] - '0';
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) solve(i, j, map[i][j]);
	}

	cout << (res * res);
}