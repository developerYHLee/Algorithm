#include <iostream>

using namespace std;

int N, M, X, Y, K;
int temp[7], dice[7], MAP[20][20], dx[5] = { 0, 0, 0, -1, 1 }, dy[5] = { 0, 1, -1, 0, 0 }, dir[4];

void print_dice() {
	cout << "print dice!\n";
	for (int i = 1; i <= 6; i++) cout << dice[i] << " ";
	cout << '\n';
}

void print_temp() {
	cout << "print temp!\n";
	for (int i = 1; i <= 6; i++) cout << temp[i] << " ";
	cout << '\n';
}

void print_dir() {
	cout << "print dir!\n";
	for (int i = 0; i <= 3; i++) cout << dir[i] << " ";
	cout << '\n';
}

void input() {
	cin >> N >> M >> X >> Y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> MAP[i][j];
	}
	for (int i = 1; i <= 6; i++) temp[i] = i;

	dir[0] = 6;
	dir[2] = 1;
}

void make_dir(int d) {
	if (d == 1) dir[1] = 3;
	else if (d == 2) dir[1] = 4;
	else if (d == 3) dir[1] = 2;
	else if (d == 4) dir[1] = 5;

	dir[3] = 7 - dir[1];
}

void change_temp(int d) {
	make_dir(d);

	int t = temp[dir[0]];
	for (int i = 1; i < 4; i++) temp[dir[i - 1]] = temp[dir[i]];
	temp[dir[3]] = t;
}

bool check_rowcol(int row, int col) {
	if (row < 0 || col < 0 || row >= N || col >= M) return false;
	return true;
}

bool move(int d) {
	int row = X + dx[d];
	int col = Y + dy[d];

	if (!check_rowcol(row, col)) return false;

	X = row;
	Y = col;

	change_temp(d);

	if (MAP[X][Y]) {
		dice[temp[6]] = MAP[X][Y];
		MAP[X][Y] = 0;
	}
	else MAP[X][Y] = dice[temp[6]];

	return true;
}

void solve(int d) {
	if (!move(d)) return;
	else cout << dice[temp[1]] << '\n';
}

int main() { //주사위 굴리기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	for (int i = 0; i < K; i++) {
		int k;
		cin >> k;
		
		solve(k);
	}
}