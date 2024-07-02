#include <iostream>
#include <cmath>
#include <memory.h>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int N, M;
bool npNum[10000], vis[10000];

void eratosthenes() {
	int sq = (int)sqrt(10000);
	for (int i = 2; i < sq; i++) {
		if (npNum[i]) continue;

		for (int j = i * i; j < 10000; j += i) npNum[j] = true;
	}
}

void input() {
	memset(vis, false, sizeof(vis));

	cin >> N >> M;
}

void solve() {
	queue<pii> Q;
	Q.push({ N, 0 });
	vis[N] = true;

	while (!Q.empty()) {
		pii node = Q.front();
		Q.pop();

		int num = node.first, cnt = node.second;

		if (num == M) {
			cout << cnt << "\n";
			return;
		}

		for (int i = 0; i < 4; i++) {
			int o = (int)pow(10, i);
			int temp = num / (10 * o) * (10 * o) + num % o;

			for (int j = 0; j < 10; j++) {
				int x = temp + o * j;

				if (x < 1000 || npNum[x] || vis[x]) continue;

				Q.push({ x, cnt + 1 });
				vis[x] = true;
			}
		}
	}

	cout << "Impossible\n";
}

int main() { //소수 경로
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	eratosthenes();

	int T;
	cin >> T;

	while (T--) {
		input();
		solve();
	}
}