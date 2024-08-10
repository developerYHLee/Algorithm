#include <iostream>
#include <vector>

using namespace std;

struct Pos {
	int x1, y1, x2, y2;

	Pos(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}
};

vector<Pos> lines[11];
int N, info[20][4], res;
bool vis[101][101];

void makeLine(int index) {
	if (index == 11) return;

	for (const Pos& p : lines[index - 1]) lines[index].push_back(p);
	
	for (int i = lines[index - 1].size() - 1; i >= 0; i--) {
		int x1 = lines[index - 1][i].x1, y1 = lines[index - 1][i].y1;
		int x2 = lines[index - 1][i].x2, y2 = lines[index - 1][i].y2;
	
		int x = x2 - x1, y = y2 - y1;
		int dx = y, dy = -x;

		x2 = lines[index][lines[index].size() - 1].x2;
		y2 = lines[index][lines[index].size() - 1].y2;

		lines[index].push_back(Pos(x2, y2, x2 + dx, y2 + dy));
	}

	makeLine(index + 1);
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> info[i][0] >> info[i][1] >> info[i][2] >> info[i][3];

	lines[0].push_back(Pos(0, 0, 1, 0));
}

void setD(int& dx, int& dy, int d) {
	if (d == 1) {
		int x = dx, y = dy;
		dx = y;
		dy = -x;
	}
	else if (d == 2) {
		int x = dx, y = dy;
		dx = -x;
		dy = -y;
	}
	else if (d == 3) {
		int x = dx, y = dy;
		dx = -y;
		dy = x;
	}
}

void setD(int& x1, int& y1, int& x2, int& y2, int d) {
	setD(x1, y1, d);
	setD(x2, y2, d);
}

void draw() {
	for (int i = 0; i < N; i++) {
		int x = info[i][0], y = info[i][1], d = info[i][2], g = info[i][3];

		for (int j = 0; j < lines[g].size(); j++) {
			int x1 = lines[g][j].x1, y1 = lines[g][j].y1;
			int x2 = lines[g][j].x2, y2 = lines[g][j].y2;
			
			setD(x1, y1, x2, y2, d);
			
			vis[x + x1][y + y1] = true;
			vis[x + x2][y + y2] = true;
		}
	}
}

void getRes() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			int x1 = i, y1 = j;
			int x2 = x1 + 1, y2 = y1 + 1;

			if (vis[x1][y1] && vis[x2][y1] && vis[x1][y2] && vis[x2][y2]) res++;
		}
	}
}

void solve() {
	makeLine(1);
	draw();
	getRes();
	cout << res;
}

int main() { //µå·¡°ï Ä¿ºê
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}