#include <iostream>
#include <cmath>
#include <vector>
#include <climits>

using namespace std;

const int MAX_BIT = 1 << 20;
int N, score[21][21], res = INT_MAX;
vector<int> S, L;
bool vis[MAX_BIT];

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> score[i][j];
	}
}

void getTeam(int bit) {
	S.clear();
	L.clear();

	int s = 0, l = 0;

	for (int i = 0; i < N; i++) {
		if (bit & (1 << i)) {
			S.push_back(i);
			s |= (1 << i);
		}

		else {
			L.push_back(i);
			l |= (1 << i);
		}
	}

	vis[s] = true;
	vis[l] = true;
}

void getScore() {
	int s = 0, l = 0;

	for (int i : S) {
		for (int j : S) s += score[i][j];
	}

	for (int i : L) {
		for (int j : L) l += score[i][j];
	}

	res = min(res, abs(s - l));
}

void recur(int index, int bit, int cnt) {
	if (cnt == N / 2) {
		if (vis[bit]) return;

		getTeam(bit);
		getScore();

		return;
	}

	for (int i = index; i < N; i++) {
		bit |= (1 << i);
		recur(i + 1, bit, cnt + 1);
		bit &= ~(1 << i);
	}
}

void solve() {
	recur(0, 0, 0);
	cout << res;
}

int main() { //스타트와 링크
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}