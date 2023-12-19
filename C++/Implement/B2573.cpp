#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;
typedef pair<int, int> pii;

bool vis[300][300];
int arr[300][300], cnt[300][300], dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 }, N, M;

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> arr[i][j];
	}
}

void solve(int startRow, int startCol) {
	queue<pii> Q;
	Q.push({ startRow, startCol });
	vis[startRow][startCol] = true;

	while (!Q.empty()) {
		pii cur = Q.front();
		Q.pop();

		int row = cur.first, col = cur.second;
		for (int i = 0; i < 4; i++) {
			int r = row + dx[i];
			int c = col + dy[i];

			if (r < 0 || c < 0 || r >= N || c >= M) continue;
			if (arr[r][c] <= 0) cnt[row][col]++;
			else if (!vis[r][c]) {
				Q.push({ r, c }); 
				vis[r][c] = true;
			}
		}
	}
}

void melt() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) arr[i][j] -= cnt[i][j];
	}
	memset(cnt, 0, sizeof(cnt));
}

int main() { //ºù»ê
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	int res = 0;
	while (true) {
		memset(vis, false, sizeof(vis));
		
		int check = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] <= 0 || vis[i][j]) continue;

				solve(i, j);
				melt();

				check++;
			}
		}

		if (check == 1) res++;
		else {
			if (!check) cout << 0;
			else if (check > 1) cout << res;
			break;
		}
	}
}