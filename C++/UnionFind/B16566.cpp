#include <iostream>
#include <algorithm>

using namespace std;

int N, M, K, p[4'000'000], card[4'000'000];

int find(int x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);

	p[y] = x;
}

void input() {
	for (int i = 0; i < 4'000'000; i++) p[i] = i;

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) cin >> card[i];
	sort(card, card + N);

	for (int i = 0; i < K; i++) {
		int num;
		cin >> num;

		auto iter = upper_bound(card, card + N, num);

		int index = iter - card;
		cout << card[find(p[index])] << "\n";
		merge(++p[index], index);
	}
}

int main() { //카드 게임
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
}