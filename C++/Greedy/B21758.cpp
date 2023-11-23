#include <iostream>
#include <algorithm>

using namespace std;

int N, arr[100000], res, total;

void solve1() {
	total -= arr[0] * 2;
	int sum = 0;
	for (int i = 1; i < N; i++) {
		res = max(res, total - (arr[i] * 2 + sum));
		sum += arr[i];
	}
	total += arr[0] * 2;
}

void solve2() {
	total -= arr[N - 1] * 2;
	int sum = 0;
	for (int i = N - 2; i >= 0; i--) {
		res = max(res, total - (arr[i] * 2 + sum));
		sum += arr[i];
	}
	total += arr[N - 1] * 2;
}

int main() { //²Ü µû±â
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		total += arr[i] * 2;
	}

	int temp = total / 2 - (arr[0] + arr[N - 1]);
	for (int i = 0; i < N; i++) res = max(res, temp + arr[i]);
	solve1();
	solve2();

	cout << res;
}