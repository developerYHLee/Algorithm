#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct Node {
	int X, cnt;

	Node(int X, int cnt) : X(X), cnt(cnt) {}
};

int X, K, path[100001];
bool vis[100001];

void input() {
	cin >> X >> K;
}

bool checkRange(int x) {
	if (x < 0 || x > 100000 || vis[x]) return false;
	return true;
}

//백트래킹, 재귀X
void getPath() {
	stack<int> S;
	int p = K;

	while (p != X) {
		S.push(p);
		p = path[p];
	}

	S.push(X);

	while (!S.empty()) {
		int node = S.top();
		S.pop();

		cout << node << " ";
	}
}

void bfs() {
	queue<Node> Q;
	Q.push(Node(X, 0));
	vis[X] = true;
	
	while (!Q.empty()) {
		Node node = Q.front();
		Q.pop();

		int x = node.X, cnt = node.cnt;

		if (x == K) {
			cout << cnt << "\n";
			return;
		}

		int next = x * 2;
		if (checkRange(next)) {
			Q.push(Node(next, cnt + 1));
			vis[next] = true;
			path[next] = x;
		}

		next = x + 1;
		if (checkRange(next)) {
			Q.push(Node(next, cnt + 1));
			vis[next] = true;
			path[next] = x;
		}

		next = x - 1;
		if (checkRange(next)) {
			Q.push(Node(next, cnt + 1));
			vis[next] = true;
			path[next] = x;
		}
	}
}

void solve() {
	if (X >= K) {
		cout << (X - K) << "\n";
		for (int i = X; i >= K; i--) cout << i << " ";
	}
	else {
		bfs();
		getPath();
	}
}

int main() { //숨바꼭질 4(역추적)
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}