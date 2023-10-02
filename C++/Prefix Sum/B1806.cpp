#include <iostream>
#include <cmath>

using namespace std;

int dp[100001];

int search(int N, int key) {
	int s = 0, e = N, mid;

	while (s <= e) {
		mid = (s + e) / 2;

		if (dp[mid] > key) e = mid - 1;
		else s = mid + 1;
	}

	return e;
}

void prefix_sum(int N) {
	for (int i = 1; i <= N; i++) dp[i] += dp[i - 1];
}

int main() { //ºÎºÐÇÕ
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, S;
	cin >> N >> S;

	for (int i = 1; i <= N; i++) cin >> dp[i];
	prefix_sum(N);

	int res = 1e9;
	for (int i = 1; i <= N; i++) {
		int key = dp[i] - S;
		if (key < 0) continue;

		int index = search(i, key);
		res = min(res, i - index);
	}

	cout << (res == 1e9 ? 0 : res);
}