#include <iostream>

using namespace std;

int N, M;
bool A[50][50], B[50][50];

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < M; j++) A[i][j] = str[j] == '0' ? false : true;
	}
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < M; j++) B[i][j] = str[j] == '0' ? false : true;
	}
}

void toggle(int row, int col) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) A[i + row][j + col] = !A[i + row][j + col];
	}
}

void solve() {
	int res = 0;
	
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 2; j++) {
			if (A[i][j] != B[i][j]) {
				res++;
				toggle(i, j);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] != B[i][j]) res = -1;
		}
	}
	
	cout << res;
}

int main() { //За·Д
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}