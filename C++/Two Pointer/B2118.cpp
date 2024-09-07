#include <iostream>
#include <cmath>

using namespace std;

int N, arr[50'000], maxLength;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		maxLength += arr[i];
	}
}

void solve() {
	int len = 0, l = 0, p = 0, halfLength = maxLength / 2, res = 0;

	while (p < N) {
		len += arr[p++];

		res = max(res, min(len, maxLength - len));
		while (len > halfLength && l < p) {
			len -= arr[l++];
			res = max(res, min(len, maxLength - len));
		}
	}

	cout << res;
}

int main() { //두 개의 탑
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}