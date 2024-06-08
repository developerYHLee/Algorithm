#include <iostream>
#include <queue>

using namespace std;

int N, M, K, money[100'001];

void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) cin >> money[i];
}

void solve() {
	int sum = 0, res = 0;
	queue<int> Q;

	for (int i = N - M + 1; i <= N; i++) {
		sum += money[i];
		Q.push(money[i]);
	}

	if (N == M) {
		cout << (sum < K) << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		int m = Q.front();
		Q.pop();

		sum += money[i] - m;
		Q.push(money[i]);

		if (sum < K) res++;
	}

	cout << res << "\n";
}

int main() { //µµµÏ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T-- > 0) {
		input();
		solve();
	}
}