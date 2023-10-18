#include <iostream>
#include <cmath>

using namespace std;

int box[51][51];
int N, M;

int solve(int joker) {
	int res = 0;
	bool* vis = new bool[M + 1]{};

	for (int i = 1; i <= N; i++) {
		if (i == joker) continue;

		int index = 0;
		for (int j = 1; j <= M; j++) {
			if (box[i][j] > 0) {
				if (index != 0 || vis[j]) {
					index = -1;
					break;
				}

				index = j;
			}
		}

		if (index == -1) res++;
		else vis[index] = true;
	}

	delete[] vis;

	return res;
}

int main() { //카드 정리 1
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) cin >> box[i][j];
	}

	int res = 1e9;
	for (int i = 1; i <= N; i++) res = min(res, solve(i));

	cout << res;
}