#include <iostream>

using namespace std;

int N, K, ham[20000];

void input() {
	cin >> N >> K;
	
	string str;
	cin >> str;

	for (int i = 0; i < N; i++) {
		if (str[i] == 'H') ham[i] = 1;
	}
}

bool checkRange(int i) {
	if (i < 0 || i >= N || !(ham[i] == 1)) return false;
	return true;
}

void solve() {
	int res = 0;
	for (int i = 0; i < N; i++) {
		if (ham[i]) continue;
		
		for (int j = -K; j <= K; j++) {
			if (!checkRange(i + j)) continue;
		
			res++;
			ham[i + j] = -1;
			break;
		}
	}

	cout << res;
}

int main() { //ÇÜ¹ö°Å ºĞ¹è
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}