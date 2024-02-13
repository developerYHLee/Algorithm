#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;

struct Node {
	int row, col, value;

	Node(int row, int col, int value) : row(row), col(col), value(value) {}
};

struct cmp {
	bool operator()(Node o1, Node o2) { return o1.value > o2.value; }
};

int rupee[125][125], N, dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };

int solve() {
	priority_queue<Node, vector<Node>, cmp> PQ;
	PQ.push(Node(0, 0, rupee[0][0]));

	while (!PQ.empty()) {
		Node node = PQ.top();
		PQ.pop();

		int row = node.row, col = node.col, value = node.value;

		if (row == N - 1 && col == N - 1) return value;
	
		for (int i = 0; i < 4; i++) {
			int r = row + dx[i];
			int c = col + dy[i];

			if (r < 0 || c < 0 || r >= N || c >= N || rupee[r][c] == -1) continue;

			PQ.push(Node(r, c, value + rupee[r][c]));
			rupee[r][c] = -1;
		}
	}

	return -1;
}

void input() {
	cin >> N;

	int cnt = 1;
	while (N) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) cin >> rupee[i][j];
		}

		cout << "Problem " << cnt++ << ": " << solve() << "\n";

		cin >> N;
	}
}

int main() { //³ì»ö ¿Ê ÀÔÀº ¾Ö°¡ Á©´ÙÁö?
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
}