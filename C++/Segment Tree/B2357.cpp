#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

const int MAX_INDEX = 410'000;
int N, M, minTree[MAX_INDEX], maxTree[MAX_INDEX], firstIndex;

void setFirstIndex() {
	firstIndex = 1;
	while (firstIndex < N) firstIndex *= 2;
}

void makeTree() {
	for (int i = firstIndex - 1; i > 0; i--) {
		minTree[i] = min(minTree[i * 2], minTree[i * 2 + 1]);
		maxTree[i] = max(maxTree[i * 2], maxTree[i * 2 + 1]);
	}
}

void input() {
	cin >> N >> M;

	setFirstIndex();
	fill_n(minTree, MAX_INDEX, INT_MAX);
	fill_n(maxTree, MAX_INDEX, INT_MIN);

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		minTree[firstIndex + i] = num;
		maxTree[firstIndex + i] = num;
	}

	makeTree();
}

int searchMinTree(int l, int r, int s, int e, int index) {
	if (r < s || l > e) return INT_MAX;
	if (s <= l && r <= e) return minTree[index];

	int m = (l + r) / 2;

	return min(searchMinTree(l, m, s, e, index * 2), searchMinTree(m + 1, r, s, e, index * 2 + 1));
}

int searchMaxTree(int l, int r, int s, int e, int index) {
	if (r < s || l > e) return INT_MIN;
	if (s <= l && r <= e) return maxTree[index];

	int m = (l + r) / 2;

	return max(searchMaxTree(l, m, s, e, index * 2), searchMaxTree(m + 1, r, s, e, index * 2 + 1));
}

void search(int s, int e) {
	cout << searchMinTree(1, firstIndex, s, e, 1) << " " << searchMaxTree(1, firstIndex, s, e, 1);
}

void solve() {
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;

		search(s, e);
		cout << "\n";
	}
}

int main() { //ÃÖ¼Ú°ª°ú ÃÖ´ñ°ª
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}