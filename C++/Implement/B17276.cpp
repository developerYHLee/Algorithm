#include <iostream>
#include <memory.h>

using namespace std;

int T, N, D, arr[500][500], temp[4][500];
void input() {
	cin >> N >> D;
	if (D < 0) D += 360;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> arr[i][j];
	}
}

void rot() {
	D -= 45;

	for (int i = 0; i < N; i++) {
		temp[0][i] = arr[N / 2][i];
		temp[1][i] = arr[i][i];
		temp[2][i] = arr[i][N / 2];
		temp[3][i] = arr[i][N - 1 - i];
	}
	
	for (int i = 0; i < N; i++) {
		arr[i][i] = temp[0][i];
		arr[i][N / 2] = temp[1][i];
		arr[i][N - 1 - i] = temp[2][i];
		arr[N / 2][N - 1 - i] = temp[3][i];
	}
}

void solve() {
	while (D > 0) rot();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cout << arr[i][j] << " ";
		cout << "\n";
	}
}

int main() { //배열 돌리기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	while (T-- > 0) {
		input();
		solve();
	}
}