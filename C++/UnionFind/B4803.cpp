#include <iostream>

using namespace std;

int T, N, M, parent[501];
bool notTree[501];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);

	if (notTree[x]) notTree[y] = true;
	parent[x] = y;
}

void input() {
	T++;

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		notTree[i] = false;
	}

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;

		x = find(x);
		y = find(y);

		if (x == y) notTree[x] = true;
		else merge(x, y);
	}

	int t = 0;
	for (int i = 1; i <= N; i++) {
		int p = find(i);
		if (!notTree[p]) {
			t++;
			notTree[p] = true;
		}
	}

	cout << "Case " << T << ": ";
	if (!t) cout << "No trees.\n";
	else if (t == 1) cout << "There is one tree.\n";
	else cout << "A forest of " << t << " trees.\n";

	cin >> N >> M;
}

int main() { //Æ®¸®
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	while (N || M) {
		input();
	}
}