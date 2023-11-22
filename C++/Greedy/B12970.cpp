#include <iostream>

using namespace std;

bool isA[51];
int N, K;

bool solve(int cnt_A) {
	int cnt = (N - cnt_A) * (cnt_A - 1);
	for (int i = N; i >= cnt_A; i--) {
		if (cnt == K) {
			isA[i] = true;
			return true;
		}
		cnt++;
	}

	return false;
}

int main() { //AB
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		if (solve(i)) {
			string res = "";
			for (int i = 1; i <= N; i++) res += isA[i] ? "A" : "B";
			cout << res;

			return 0;
		}
		isA[i] = true;
	}

	cout << -1;
}