#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct Node {
	int cnt, row, col;
	bool v;

	Node(int _cnt, int _row, int _col, bool _v) : cnt(_cnt), row(_row), col(_col), v(_v) {};
};

queue<Node> Q;
char map[50][50];
bool vis[50][50][2];
int N, dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };

int check(int row, int col, bool v, int cnt) {
	int ret = 0;

	if (map[row][col] == '*' || vis[row][col][v]) ret = -1;
	else if (map[row][col] == '!') Q.push(Node(cnt + 1, row, col, !v));
	else if (map[row][col] == '#') {
		Q.push(Node(cnt, row, col, true));
		Q.push(Node(cnt, row, col, false));
		ret = 1;
	}

	vis[row][col][v] = true;
	return ret;
}

int main() { //거울 설치
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < N; j++) {
			map[i][j] = str[j];

			if (Q.size() == 0 && map[i][j] == '#') check(i, j, true, 0);
		}
	}
	
	while (!Q.empty()) {
		Node cur = Q.front();
		Q.pop();

		int cnt = cur.cnt, row = cur.row, col = cur.col;
		bool v = cur.v;
		
		//상/하로 이동
		if (v) {
			int r = row - 1;
			while (r >= 0) {
				int x = check(r, col, v, cnt);

				if (x == -1) break;
				else if (x == 1) {
					cout << cnt;
					return 0;
				}

				r--;
			}

			r = row + 1;
			while (r < N) {
				int x = check(r, col, v, cnt);

				if (x == -1) break;
				else if (x == 1) {
					cout << cnt;
					return 0;
				}

				r++;
			}
		}
		//좌/우로 이동
		else {
			int c = col - 1;
			while (c >= 0) {
				int x = check(row, c, v, cnt);

				if (x == -1) break;
				else if (x == 1) {
					cout << cnt;
					return 0;
				}

				c--;
			}

			c = col + 1;
			while (c < N) {
				int x = check(row, c, v, cnt);

				if (x == -1) break;
				else if (x == 1) {
					cout << cnt;
					return 0;
				}

				c++;
			}
		}
	}
}