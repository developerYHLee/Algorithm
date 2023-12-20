#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000], N, res[2], MIN = 2e9;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
}

void b_s(int start) {
	int key = arr[start], s = start + 1, e = N;

	while (s < e) {
		int mid = (s + e) >> 1, k = key + arr[mid];

		if (MIN > abs(k)) {
			MIN = abs(k);
			res[0] = key;
			res[1] = arr[mid];
		}
		
		if (k >= 0) e = mid;
		else s = mid + 1;
	}
}

void solve() {
	for (int i = 0; i < N - 1; i++) b_s(i);
	cout << res[0] << " " << res[1];
}

int main() { //µÎ ¿ë¾×
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}