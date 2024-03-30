#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int temp[3];
vector<int> res;
bool vis[201][201][201];

void input() { 
	for (int i = 0; i < 3; i++) cin >> temp[i];
}

void recur(int A, int B, int C) {
	if (vis[A][B][C]) return;
	vis[A][B][C] = true;

	if (!A) { res.push_back(C); }

	int move = 0;
	if (A) {
		move = temp[1] - B;
		if (A > move) {
			recur(A - move, B + move, C);

			int move2 = temp[2] - C;
			if (A - move >= move2) recur(A - move - move2, B + move, C + move2);
		}
		else recur(0, B + A, C);

		move = temp[2] - C;
		if (A > move) {
			recur(A - move, B, C + move);

			int move2 = temp[1] - B;
			if (A - move >= move2) recur(A - move - move2, B + move2, C + move);
		}
		else recur(0, B, C + A);
	}
	if (B) {
		move = temp[0] - A;
		if (B > move) {
			recur(A + move, B - move, C);

			int move2 = temp[2] - C;
			if (B - move >= move2) recur(A + move, B - move - move2, C + move2);
		}
		else recur(A + B, 0, C);

		move = temp[2] - C;
		if (B > move) {
			recur(A, B - move, C + move);

			int move2 = temp[0] - A;
			if (B - move >= move2) recur(A + move2, B - move - move2, C + move);
		}
		else recur(A, 0, C + B);
	}
	if (C) {
		move = temp[0] - A;
		if (C > move) {
			recur(A + move, B, C - move);

			int move2 = temp[1] - B;
			if (C - move >= move2) recur(A + move, B + move2, C - move - move2);
		}
		else recur(A + C, B, 0);

		move = temp[1] - B;
		if (C > move) {
			recur(A, B + move, C - move);

			int move2 = temp[0] - A;
			if (B - move >= move2) recur(A + move2, B + move, C - move - move2);
		}
		else recur(A, B + C, 0);
	}
}

void solve() {
	recur(0, 0, temp[2]);
	sort(res.begin(), res.end());

	for (int r : res) cout << r << " ";
}

int main() { //¹°Åë
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}