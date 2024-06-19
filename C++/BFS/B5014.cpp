#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

const int MAX = 1'000'001;
int F, S, G, U, D;
bool vis[MAX];

void input() {
	cin >> F >> S >> G >> U >> D;
}

void bfs() {
	queue<pii> Q;
	Q.push({ S, 0 });

	while (!Q.empty()) {
		pii node = Q.front();
		Q.pop();

		int f = node.first, cnt = node.second;

		if (f <= 0 || f > F || vis[f]) continue;
		vis[f] = true;

		if (f == G) {
			cout << cnt;
			return;
		}

		Q.push({ f + U, cnt + 1 });
		Q.push({ f - D, cnt + 1 });
	}

	cout << "use the stairs";
}

void solve() {
	bfs();
}

int main() { //스타트링크
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}