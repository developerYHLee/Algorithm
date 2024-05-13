#include <iostream>
#include <algorithm>

using namespace std;

const int MUL = 10'000'000;
int X, N, L[1'000'000];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> L[i];
	sort(L, L + N);

	X *= MUL;
}

void solve() {
	int l = 0, r = N - 1;
	
	while (l < r) {
		int key = L[l] + L[r];

		if (X == key) break;
		else if (X < key) r--;
		else l++;
	}

	if (l >= r) cout << "danger\n";
	else cout << "yes " << L[l] << " " << L[r] << "\n";
}

int main() { //로봇 프로젝트
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (cin >> X) {
		input();
		solve();
	}
}