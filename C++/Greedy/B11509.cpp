#include <iostream>

using namespace std;

int N, H[1'000'000], temp[1'000'001];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> H[i];
}

void solve() {
	int res = 0;
	for (int i = 0; i < N; i++) {
		temp[H[i]]++;
		if (temp[H[i] + 1]) temp[H[i] + 1]--;
		else res++;
	}

	cout << res;
}

int main() { //Ç³¼± ¸ÂÃß±â
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}