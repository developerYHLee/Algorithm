#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Node {
	int h, r, c, cnt;
	
	Node(int h, int r, int c, int cnt) : h(h), r(r), c(c), cnt(cnt) {}
};

char build[30][30][30];
int H, R, C, index;
queue<Node> Q;

void solve() {
	int dx[6] = { 1, -1, 0, 0, 0, 0 }, dy[6] = { 0, 0, 1, -1, 0, 0 }, dz[6] = { 0, 0, 0, 0, 1, -1 };

	while (!Q.empty()) {
		Node node = Q.front();
		Q.pop();

		int height = node.h, row = node.r, col = node.c, nextCnt = node.cnt + 1;

		for (int i = 0; i < 6; i++) {
			int h = height + dz[i];
			int r = row + dx[i];
			int c = col + dy[i];

			if (h < 0 || r < 0 || c < 0 || h >= H || r >= R || c >= C || build[h][r][c] == '#') continue;
			if (build[h][r][c] == 'E') {
				cout << "Escaped in " << nextCnt << " minute(s).\n";
				return;
			}

			Q.push(Node(h, r, c, nextCnt));
			build[h][r][c] = '#';
		}
	}

	cout << "Trapped!\n";
}

int get_num(string& str) {
	int ret = 0;
	
	while (index < str.length()) {
		if (str[index] == ' ') {
			index++;
			break;
		}

		ret = ret * 10 + str[index] - '0';
		index++;
	}

	return ret;
}

void input() {
	string str;

	while (getline(cin, str)) {
		Q = queue<Node>();
		index = 0;

		H = get_num(str);
		R = get_num(str);
		C = get_num(str);

		if (H == 0 && R == 0 && C == 0) break;

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < R; j++) {
				getline(cin, str);

				for (int k = 0; k < C; k++) {
					build[i][j][k] = str[k];

					if (build[i][j][k] == 'S') {
						Q.push(Node(i, j, k, 0));
						build[i][j][k] = '#';
					}
				}
			}
			getline(cin, str);
		}

		solve();
	}
}

int main() { //»ó¹ü ºôµù
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
}