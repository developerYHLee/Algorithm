#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> f;
int N;
bool vis[2000];

void input() {
	int M;
	cin >> N >> M;
	f.resize(N);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		f[a].push_back(b);
		f[b].push_back(a);
	}
}

bool dfs(int index, int cnt) {
	if (cnt == 5) return true;

	for (int i : f[index]) {
		if (vis[i]) continue;

		vis[i] = true;
		if (dfs(i, cnt + 1)) return true;
		vis[i] = false;
	}

	return false;
}

void solve() {
	for (int i = 0; i < N; i++) {
		vis[i] = true;
		if (dfs(i, 1)) {
			cout << 1;
			return;
		}
		vis[i] = false;
	}
	cout << 0;
}

int main() { //ABCDE
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}