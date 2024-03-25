#include <iostream>
#include <cmath>

using namespace std;

int arr[81], N;

void input() { cin >> N; }

bool checkArr(int index) {
	for (int i = index / 2; i > 0; i--) {
		bool ch = false;
		for (int j = 0; j < i; j++) {
			if (arr[index - j] != arr[index - (i + j)]) ch = true;
		}
		if (!ch) return false;
	}

	return true;
}

bool backtracking(int index) {
	if (index == N) return true;

	for (int i = 1; i <= 3; i++) {
		arr[index] = i;
		if (checkArr(index) && backtracking(index + 1)) return true;
	}

	return false;
}

void solve() {
	N++;
	backtracking(1);

	for (int i = 1; i < N; i++) cout << arr[i];
}

int main() { //좋은수열
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}