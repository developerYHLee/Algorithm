#include <iostream>

using namespace std;
typedef long long ll;

int N, Q, firstIndex;
ll arr[410'000];

void setFirstIndex() {
	firstIndex = 1;
	while (firstIndex <= N) firstIndex *= 2;
}

void setArr() {
	for (int i = firstIndex - 1; i > 0; i--) arr[i] = arr[i * 2] + arr[i * 2 + 1];
}

void input() {
	cin >> N >> Q;
	
	setFirstIndex();
	for (int i = 0; i < N; i++) cin >> arr[firstIndex + i];
	setArr();
}

ll printSum(int s, int e, int l, int r, int index) {
	if (s > r || e < l) return 0;
	if (s <= l && r <= e) return arr[index];

	int m = (l + r) / 2;

	return printSum(s, e, l, m, index * 2) + printSum(s, e, m + 1, r, index * 2 + 1);
}

void changeNum(int index, int num) {
	arr[index] = num;

	while (index) {
		index /= 2;
		arr[index] = arr[index * 2] + arr[index * 2 + 1];
	}
}

void solve() {
	for (int i = 0; i < Q; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;

		if (x > y) swap(x, y);

		cout << printSum(x, y, 1, firstIndex, 1) << "\n";
		changeNum(firstIndex + a - 1, b);
	}
}

int main() { //Ä¿ÇÇ¼ó2
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}