#include <iostream>
#include <algorithm>

using namespace std;

int N, K, x[10000], dis[10000];

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> x[i];
}

void solve() {
	sort(x, x + N);
	
	for (int i = 0; i < N - 1; i++) dis[i] = x[i + 1] - x[i];
	sort(dis, dis + N - 1);

	int res = 0;
	for (int i = 0; i < N - K; i++) res += dis[i];
	cout << res;
}

int main() { //¼¾¼­
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}