#include <iostream>

using namespace std;

int N, S, arr[20], res;

void input() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> arr[i];
}

void recur(int index, int sum) {
	if (index == N) {
		if (sum == S) res++;
		return;
	}

	recur(index + 1, sum + arr[index]);
	recur(index + 1, sum);
}

void solve() {
	if (!S) res--;
	recur(0, 0);
	cout << res;
}

int main() { //부분수열의 합
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}