#include <iostream>
#include <cmath>

using namespace std;

int N, res, arr[100'000];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	res = 1e9;
}

void solve() {
	int l = 0, r = N - 1, sum;

	while (l < r) {
		sum = arr[r] + arr[l];
		
		if (abs(res) > abs(sum)) res = sum;

		if (sum > 0) r--;
		else l++;
	}

	cout << res;
}

int main() { //용액 합성하기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}