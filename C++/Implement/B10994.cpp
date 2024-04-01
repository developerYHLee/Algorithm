#include <iostream>
#include <cmath>

using namespace std;

int N;
bool star[400][400];

void input() { cin >> N; }

void recur(int k) {
	if (k == N) return;

	int x = 2 * (N - (k + 1)), y = 4 * k;
	for (int i = 0; i <= y; i++) star[x][x + i] = true;
	for (int i = 1; i < y; i++) {
		star[x + i][x] = true;
		star[x + i][x + y] = true;
	}
	for (int i = 0; i <= y; i++) star[x + y][x + i] = true;
	recur(k + 1);
}

void solve() {
	int x = 2 * (N - 1);
	star[x][x] = true;
	recur(1);

	x = 4 * (N - 1);
	for (int i = 0; i <= x; i++) {
		for (int j = 0; j <= x; j++) {
			if (star[i][j]) cout << "*";
			else cout << " ";
		}
		cout << "\n";
	}
}

int main() { //º° Âï±â - 19
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}