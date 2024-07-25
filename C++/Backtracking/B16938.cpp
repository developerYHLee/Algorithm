#include <iostream>
#include <cmath>

using namespace std;

int N, L, R, X, arr[15], res;

void input() {
	cin >> N >> L >> R >> X;
	for (int i = 0; i < N; i++) cin >> arr[i];
}

bool check(int sum, int gap) {
	if (sum < L || sum > R) return false;
	if (gap < X) return false;

	return true;
}

void recur(int index, int sum, int minNum, int maxNum) {
	if (index == N) {
		if (check(sum, maxNum - minNum)) res++;
		return;
	}

	recur(index + 1, sum + arr[index], min(minNum, arr[index]), max(maxNum, arr[index]));
	recur(index + 1, sum, minNum, maxNum);
}

void solve() {
	recur(0, 0, 1e9, 0);
	cout << res;
}

int main() { //Ä·ÇÁ ÁØºñ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}