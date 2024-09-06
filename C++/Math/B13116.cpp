#include <iostream>
#include <memory.h>

using namespace std;

int A, B, res;
bool vis[1024];

void input() {
	memset(vis, false, sizeof(vis));
	cin >> A >> B;
}

void recur(int num) {
	if (vis[num]) {
		res = num;
		return;
	}
	if (!num) return;

	vis[num] = true;
	recur(num / 2);
}

void solve() {
	recur(A);
	recur(B);
	cout << res * 10 << "\n";
}

int main() { //30¹ø
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		input();
		solve();
	}
}