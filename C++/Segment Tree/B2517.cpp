#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;
typedef vector<int> vi;

int N, arr[500'001], sortArr[500'001];
vi tree[2'100'000];

void mergeSort(int l, int m, int r, int index) {
	int* temp = new int[r - l + 1];

	int p1 = l, p2 = m + 1, tIndex = 0;
	while (p1 <= m && p2 <= r) {
		if (sortArr[p1] <= sortArr[p2]) temp[tIndex++] = sortArr[p1++];
		else temp[tIndex++] = sortArr[p2++];
	}

	while (p1 <= m) temp[tIndex++] = sortArr[p1++];
	while (p2 <= r) temp[tIndex++] = sortArr[p2++];

	vi v;
	for (int i = l; i <= r; i++) {
		int n = temp[i - l];
		v.push_back(n);
		sortArr[i] = n;
	}
	delete[] temp;

	tree[index] = v;
}

void merge(int l, int r, int index) {
	int m = (l + r) / 2;

	if (l < r) {
		merge(l, m, index * 2);
		merge(m + 1, r, index * 2 + 1);
	}
	
	mergeSort(l, m, r, index);
}

void mergeSort() {
	merge(1, N, 1);
}

void input() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		sortArr[i] = arr[i];
	}

	mergeSort();
}

int findTree(int s, int e, int l, int r, int index, int key) {
	if (e < l || r < s) return 0;
	if (s <= l && r <= e) {
		auto iter = upper_bound(tree[index].begin(), tree[index].end(), key);
		return iter - tree[index].begin();
	}

	int m = (l + r) / 2;
	return findTree(s, e, l, m, index * 2, key) + findTree(s, e, m + 1, r, index * 2 + 1, key);
}

void solve() {
	cout << 1 << "\n";
	for (int i = 2; i <= N; i++) cout << i - findTree(1, i - 1, 1, N, 1, arr[i]) << "\n";
}

int main() { //´Þ¸®±â
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}