#include <iostream>

using namespace std;

int G, P, parent[100001], plane[100001];

void input() {
	cin >> G >> P;
	for (int i = 1; i <= P; i++) cin >> plane[i];
	for (int i = 1; i <= G; i++) parent[i] = i;
}

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void solve() {
	int res = 0;
	for (int i = 1; i <= P; i++) {
		int x = find(plane[i]);

		if (!x) {
			cout << res;
			return;
		}
		parent[x]--;
		res++;
	}

	cout << res;
}

int main() { //°øÇ×
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}