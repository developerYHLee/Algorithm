#include <iostream>
#include <queue>
#include <cmath>;

using namespace std;
typedef pair<int, int> pii;

int N, Q, sz, ice_cnt, ice_sz, A[100][100], L[1000], temp_A[100][100], dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
bool vis[100][100];

bool check_rowcol(int row, int col, bool isBfs) {
	if (row < 0 || col < 0 || row >= sz || col >= sz || (isBfs && vis[row][col])) return false;
	return true;
}

void change_A() {
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			temp_A[i][j] = A[i][j];

			if (!A[i][j]) continue;
			
			int ice = 0;

			for (int k = 0; k < 4; k++) {
				int r = i + dx[k];
				int c = j + dy[k];

				if (!check_rowcol(r, c, false)) continue;
				if (A[r][c]) ice++;
			}

			if (ice < 3) temp_A[i][j]--;
		}
	}

	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) A[i][j] = temp_A[i][j];
	}
}

void recur(int cnt, int s_r, int s_c, int e_r, int e_c) {
	if (cnt <= 1) return;

	int cur_sz = cnt - 1;
	for (int i = 0; i < cur_sz; i++) {
		int n1 = A[s_r][s_c + i], n2 = A[s_r + i][e_c], n3 = A[e_r][e_c - i], n4 = A[e_r - i][s_c];
		A[s_r][s_c + i] = n4;
		A[s_r + i][e_c] = n1;
		A[e_r][e_c - i] = n2;
		A[e_r - i][s_c] = n3;
	}

	recur(cnt - 2, s_r + 1, s_c + 1, e_r - 1, e_c - 1);
}

void skill(int l, int s_r, int s_c, int e_r, int e_c) {
	if (s_r == sz) return;
	
	int cur_sz = pow(2, l);
	if (s_c == sz) {
		skill(l, s_r + cur_sz, 0, e_r + cur_sz, cur_sz - 1);
		return;
	}

	recur(pow(2, l), s_r, s_c, e_r, e_c);
	skill(l, s_r, s_c + cur_sz, e_r, e_c + cur_sz);
}

void cast() {
	for (int i = 0; i < Q; i++) {
		int cur_sz = pow(2, L[i]) - 1;

		skill(L[i], 0, 0, cur_sz, cur_sz);
		change_A();
	}
}

int bfs(int startRow, int startCol) {
	int ret = 0;

	queue<pii> Q;
	Q.push({ startRow, startCol });
	vis[startRow][startCol] = true;

	while (!Q.empty()) {
		pii node = Q.front();
		Q.pop();

		int row = node.first, col = node.second;
		
		ret++;
		ice_cnt += A[row][col];

		for (int i = 0; i < 4; i++) {
			int r = row + dx[i];
			int c = col + dy[i];

			if (!check_rowcol(r, c, true) || !A[r][c]) continue;
			
			vis[r][c] = true;
			Q.push({ r, c });
		}
	}

	return ret;
}

void check_A() {
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			if (vis[i][j] || !A[i][j]) continue;
		
			ice_sz = max(ice_sz, bfs(i, j));
		}
	}
}

void input() {
	cin >> N >> Q;
	sz = pow(2, N);

	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) cin >> A[i][j];
	}
	for (int i = 0; i < Q; i++) cin >> L[i];
}

int main() { //마법사 상어와 파이어스톰
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	cast();
	check_A();
	cout << ice_cnt << "\n" << ice_sz;
}