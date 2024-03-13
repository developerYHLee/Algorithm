#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <memory.h>

using namespace std;
typedef vector<int> vi;

struct Node {
	int X, cnt;
	vi path;

	Node(int X, int cnt, vi& v) : X(X), cnt(cnt), path(v) {}
	void AddPath(int x) { path.push_back(x); }
};

int X, K;
bool vis[100001];

void input() {
	cin >> X >> K;
}

bool checkRange(int x) {
	if (x < 0 || x > 100000 || vis[x]) return false;
	return true;
}

void bfs() {
	queue<Node> Q;

	vi v;
	v.push_back(X);

	Q.push(Node(X, 0, v));
	vis[X] = true;

	while (!Q.empty()) {
		Node node = Q.front();
		Q.pop();

		int curX = node.X;

		if (curX == K) {
			cout << node.cnt << "\n";
			for (int i : node.path) cout << i << " ";
			return;
		}

		if (checkRange(curX * 2)) {
			Node next = Node(curX * 2, node.cnt + 1, node.path);
			next.AddPath(curX * 2);
			
			Q.push(next);
			vis[curX * 2] = true;
		}
		if (checkRange(curX + 1)) {
			Node next = Node(curX + 1, node.cnt + 1, node.path);
			next.AddPath(curX + 1);

			Q.push(next);
			vis[curX + 1] = true;
		}
		if (checkRange(curX - 1)) {
			Node next = Node(curX - 1, node.cnt + 1, node.path);
			next.AddPath(curX - 1);

			Q.push(next);
			vis[curX - 1] = true;
		}
	}
}

void solve() {
	if (X >= K) {
		cout << (X - K) << "\n";
		for (int i = X; i >= K; i--) cout << i << " ";
	}
	else bfs();
}

int main() { //¼û¹Ù²ÀÁú 4
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}