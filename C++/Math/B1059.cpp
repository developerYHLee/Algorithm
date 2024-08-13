#include <iostream>
#include <algorithm>

using namespace std;

int L, arr[51], N;

void input() {
	cin >> L;
	for (int i = 1; i <= L; i++) cin >> arr[i];
	cin >> N;
}

void solve() {
	sort(arr, arr + L + 1);

	auto iter = upper_bound(arr, arr + L + 1, N);
	int index = iter - arr - 1, l = arr[index];

	if (l >= N) {
		cout << 0;
		return;
	}
	
	int res = 0, r = arr[index + 1] - 1;
	for (int i = l + 1; i <= N && i <= r; i++) {
		res += r - N;
		if (i < N) res++;
	}
	cout << res;
}

int main() { //좋은 구간
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}