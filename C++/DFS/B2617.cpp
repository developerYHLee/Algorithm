#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int N, M;
bool vis[100];
vector<int> L[100], H[100];

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		L[a].push_back(b);
		H[b].push_back(a);
	}
}

int searchL(int index) {
	if (vis[index]) return 0;
	vis[index] = true;

	int ret = 1;
	for (int i : L[index]) ret += searchL(i);

	return ret;
}

int searchH(int index) {
	if (vis[index]) return 0;
	vis[index] = true;

	int ret = 1;
	for (int i : H[index]) ret += searchH(i);

	return ret;
}

void solve() {
	int res = 0;

	for (int i = 1; i <= N; i++) {
		memset(vis, false, sizeof(vis));
		int l = searchL(i);
		memset(vis, false, sizeof(vis));
		int h = searchH(i);

		if (l > (N + 1) / 2 || h > (N + 1) / 2) res++;
	}

	cout << res;
}

int main() { //구슬 찾기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}