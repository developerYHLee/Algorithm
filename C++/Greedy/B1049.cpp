#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int res, N, M, S[100], A[100];

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) cin >> S[i] >> A[i];
}

void solve() {
	while (N > 0) {
		int temp = 10000, cnt = min(6, N);

		for (int i = 0; i < M; i++) temp = min({ temp, S[i], A[i] * cnt });
		
		N -= 6;
		res += temp;
	}

	cout << res;
}

int main() { //±âÅ¸ÁÙ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}