#include <iostream>
#include <cmath>

using namespace std;

int N, K, arr[100'000];

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];
}

void solve() {
	int sum = 0, res = 0;
	
	for (int i = 0; i < K; i++) sum += arr[i];
	res = sum;
	
	for (int i = K; i < N; i++) {
		sum += arr[i] - arr[i - K];
		res = max(res, sum);
	}

	cout << res;
}

int main() { //¼ö¿­
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}