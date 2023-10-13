#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

char map[1001][1001];
int vis[1001][1001];
int R, C, res;
int dx[4]{ 1, 0 , -1, 0 }, dy[4]{ 0, -1, 0, 1 };
char dir[4]{ 'U', 'R', 'D', 'L' };

void reverse(int, int);
void check_reverse(int i, int r, int c) {	
	if (map[r][c] == dir[i]) {
		vis[r][c] = 2;
		reverse(r, c);
	}
}

void reverse(int row, int col) {
	for (int i = 0; i < 4; i++) {
		int r = row + dx[i], c = col + dy[i];

		if (r < 0 || c < 0 || r >= R || c >= C || vis[r][c] == 2) continue;
		
		check_reverse(i, r, c);
	}
}

void solve(int i, int j) {
	queue<pii> Q;
	Q.push({ i, j });

	while (!Q.empty()) {
		pii cur = Q.front();
		Q.pop();

		int row = cur.first, col = cur.second;
		if (vis[row][col] > 0) {
			res++;
			vis[row][col] = 2;
			reverse(row, col);
			return;
		}
		vis[row][col] = 1;

		if (map[row][col] == 'U') Q.push({ row - 1, col });
		else if(map[row][col] == 'R') Q.push({ row, col + 1 });
		else if(map[row][col] == 'D') Q.push({ row + 1, col });
		else Q.push({ row, col - 1 });
	}
}

int main() { //피리 부는 사나이
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	R, C;
	cin >> R >> C;
	
	for (int i = 0; i < R; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < C; j++) map[i][j] = str[j];
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (vis[i][j] > 0) continue;

			solve(i, j);
		}
	}
	
	cout << res;
}