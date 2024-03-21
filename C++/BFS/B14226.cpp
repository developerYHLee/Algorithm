#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
	int w, c, t;

	Node(int w, int c, int t) : w(w), c(c), t(t) {}
};

int S, res, vis[1001][1001];

void input() {
	cin >> S;
	for (int i = 1; i <= 1000; i++) fill_n(vis[i], 1001, 1e9);
	res = 1e9;
}

void solve() {
	queue<Node> Q;
	Q.push(Node(1, 0, 0));

	while (!Q.empty()) {
		Node node = Q.front();
		Q.pop();

		int w = node.w, c = node.c, t = node.t;

		if (w == S) res = min(res, t);
		t++;

		//Copy to Clipboard
		if (w > 0 && vis[w][w] > t) {
			vis[w][w] = min(vis[w][w], t);
			Q.push(Node(w, w, t));
		}

		//Paste to Screen
		if (c > 0 && w + c <= 1000 && vis[w + c][c] > t) {
			vis[w + c][c] = min(vis[w + c][c], t);
			Q.push(Node(w + c, c, t));
		}

		//Delete a Emoticon
		if (w >= 1 && vis[w - 1][c] > t) {
			vis[w - 1][c] = min(vis[w - 1][c], t);
			Q.push(Node(w - 1, c, t));
		}
	}

	cout << res;
}

int main() { //이모티콘
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}