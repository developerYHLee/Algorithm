#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

struct Node {
	int row, col;
	char color;

	Node(int row, int col, char color) : row(row), col(col), color(color) {}
};

char field[12][6];
bool ch;
int res, dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };

void printField() {
	cout << "PRINT FIELD\n";
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) cout << field[i][j];
		cout << "\n";
	}
	cout << "\n";
}

void input() {
	for (int i = 0; i < 12; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < 6; j++) field[i][j] = str[j];
	}
}

bool checkRange(int row, int col, char color) {
	if (row < 0 || col < 0 || row >= 12 || col >= 6 || color != field[row][col]) return false;
	return true;
}

void bfs(int sR, int sC) {
	queue<Node> Q;
	Q.push(Node(sR, sC, field[sR][sC]));

	vector<Node> bomb;
	bomb.push_back(Node(sR, sC, field[sR][sC]));

	field[sR][sC] = '.';

	while (!Q.empty()) {
		Node node = Q.front();
		Q.pop();
		
		int row = node.row, col = node.col;
		char color = node.color;
		
		for (int i = 0; i < 4; i++) {
			int r = row + dx[i];
			int c = col + dy[i];

			if (!checkRange(r, c, color)) continue;

			Q.push(Node(r, c, field[r][c]));
			bomb.push_back(Node(r, c, field[r][c]));
			field[r][c] = '.';
		}
	}

	if (bomb.size() >= 4) ch = true;
	else {
		for (Node node : bomb) {
			int row = node.row, col = node.col;
			char color = node.color;

			field[row][col] = color;
		}
	}
}

void resetField() {
	for (int j = 0; j < 6; j++) {
		int e = -1;

		for (int i = 11; i >= 0; i--) {
			if (field[i][j] == '.') e = max(i, e);
			else if (e != -1) {
				field[e--][j] = field[i][j];
				field[i][j] = '.';
			}
		}
	}
}

void solve() {
	while (true) {
		ch = false;

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (field[i][j] == '.') continue;
				bfs(i, j);
			}
		}

		if (!ch) {
			cout << res;
			return;
		}

		res++;
		resetField();
		//printField();
	}
}

int main() { //Puyo Puyo
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}