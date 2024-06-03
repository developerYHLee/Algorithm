#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int N, D, K, C, cnt[3001], belt[30000];

void input() {
	cin >> N >> D >> K >> C;

	for (int i = 0; i < N; i++) cin >> belt[i];
}

void solve() {
	queue<int> Q;
	int res = 1, temp = 1;

	cnt[C]++;
	for (int i = N - K; i < N; i++) {
		if (!cnt[belt[i]]++) {
			temp++;
			res++;
		}
		Q.push(belt[i]);
	}

	for (int i = 0; i < N; i++) {
		int p = Q.front();
		Q.pop();

		if (!--cnt[p]) temp--;
		if (!cnt[belt[i]]++) temp++;
		res = max(res, temp);

		Q.push(belt[i]);
	}

	cout << res;
}

int main() { //È¸Àü ÃÊ¹ä
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}