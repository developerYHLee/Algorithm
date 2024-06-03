#include <iostream>
#include <queue>

using namespace std;

int N, M, light[1'000'001], cnt[1'000'001];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> light[i];
	M = M * 2 - 1;
}

void solve() {
	queue<int> Q;
	priority_queue<int> PQ;
	for (int i = 1; i < M; i++) {
		Q.push(light[i]);
		if (!cnt[light[i]]++) PQ.push(light[i]);
	}

	for (int i = M; i <= N; i++) {
		Q.push(light[i]);
		if (!cnt[light[i]]++) PQ.push(light[i]);
		cout << PQ.top() << " ";

		cnt[Q.front()]--;
		Q.pop();

		while (!PQ.empty()) {
			if (cnt[PQ.top()]) break;
			PQ.pop();
		}
	}
}

int main() { //´Þ·Á¶ó È«ÁØ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}