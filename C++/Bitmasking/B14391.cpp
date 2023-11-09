#include <iostream>
#include <cmath>

using namespace std;

int map[4][4], N, M;

int main() { ///종이 조각
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < M; j++) map[i][j] = str[j] - '0';
	}
	
	int res = 0;
	for (int i = 0; i < (1 << (N * M)); i++) {
		int sum = 0;

		//가로
		for (int r = 0; r < N; r++) {
			int value = 0;

			for (int c = 0; c < M; c++) {
				if (i & (1 << r * M + c)) {
					sum += value;
					value = 0;
				}
				else value = value * 10 + map[r][c];
			}

			sum += value;
		}

		//세로
		for (int c = 0; c < M; c++) {
			int value = 0;

			for (int r = 0; r < N; r++) {
				if (i & (1 << r * M + c)) value = value * 10 + map[r][c];
				else {
					sum += value;
					value = 0;
				}
			}

			sum += value;
		}

		res = max(res, sum);
	}

	cout << res;
}