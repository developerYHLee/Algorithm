#include <iostream>
#include <queue>

using namespace std;

struct Node {
	int row, col, t, k;

	Node(int row, int col, int t, int k) : row(row), col(col), t(t), k(k) {}

	bool operator<(Node o) const {
		if (t == o.t) return k > o.k;
		return t > o.t;
	}
};

int N, K, S, X, Y, arr[201][201], dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
priority_queue<Node> PQ;

void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		
			if (arr[i][j]) PQ.push(Node(i, j, 0, arr[i][j]));
		}
	}
	cin >> S >> X >> Y;
}

bool check(int row, int col) {
	if (row == 0 || col == 0 || row > N || col > N || arr[row][col]) return false;
	return true;
}

void solve() {
	while (!PQ.empty()) {
		Node node = PQ.top();
		PQ.pop();

		int row = node.row, col = node.col, t = node.t, k = node.k;

		if (t == S) {
			cout << arr[X][Y];
			return;
		}

		for (int i = 0; i < 4; i++) {
			int r = row + dx[i];
			int c = col + dy[i];

			if (!check(r, c)) continue;

			arr[r][c] = k;
			PQ.push(Node(r, c, t + 1, arr[r][c]));
		}
	}

	cout << arr[X][Y];
}

int main() { //°æÀïÀû Àü¿°
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}