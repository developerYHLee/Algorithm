#include <iostream>

using namespace std;
typedef long long ll;

int N, M, firstIndex;
ll arr[4'100'000];

void setFirstIndex() {
	firstIndex = 1;
	while (firstIndex <= N) firstIndex *= 2;
}

void input() {
	cin >> N >> M;
	setFirstIndex();
}

ll printSum(int s, int e, int l, int r, int index) {
	if (e < l || r < s) return 0;
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
	for (int i = 0; i < M; i++) {
		int o, a, b;
		cin >> o >> a >> b;

		if (!o) {
			if (a > b) swap(a, b);
			cout << printSum(a, b, 1, firstIndex, 1) << "\n";
		}
		else changeNum(firstIndex - 1 + a, b);
	}
}

int main() { //수들의 합 7
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}