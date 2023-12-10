#include <iostream>
#include <memory.h>
#include <cmath>

using namespace std;

int arr[100][100], N, L;
bool vis[100][100];

void input() {
	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> arr[i][j];
	}
}

void reset_vis() {
	for (int j = 0; j < N; j++) memset(vis[j], false, N * sizeof(bool));
}

bool comp_row(int row, int col, int p) {
	int temp = arr[row][col];

	for (int i = col, cnt = 0; cnt < L; i += p, cnt++) {
		if (i < 0 || i >= N || temp != arr[row][i] || vis[row][i]) return false;
		vis[row][i] = true;
	}

	return true;
}

bool comp_col(int row, int col, int p) {
	int temp = arr[row][col];

	for (int i = row, cnt = 0; cnt < L; i += p, cnt++) {
		if (i < 0 || i >= N || temp != arr[i][col] || vis[i][col]) return false;
		vis[i][col] = true;
	}

	return true;
}

bool check_row(int row) {
	reset_vis();

	int prev = arr[row][0];
	for (int i = 1; i < N; i++) {
		int p = prev - arr[row][i];

		if (!p) continue;
		if (abs(p) > 1 || !comp_row(row, p > 0 ? i : i - 1, p)) return false;

		prev = arr[row][i];
	}

	return true;
}

bool check_col(int col) {
	reset_vis();

	int prev = arr[0][col];
	for (int i = 1; i < N; i++) {
		int p = prev - arr[i][col];

		if (!p) continue;
		if (abs(p) > 1 || !comp_col(p > 0 ? i : i - 1, col, p)) return false;
		
		prev = arr[i][col];
	}

	return true;
}

int solve() {
	int ret = 0;

	for (int i = 0; i < N; i++) {
		if (check_row(i)) ret++;
		if (check_col(i)) ret++;
	}

	return ret;
}

int main() { //°æ»ç·Î
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	cout << solve();
}