#include <iostream>

using namespace std;
typedef pair<int, int> pii;

const int SubFirstBit = 127, FirstBit = 128;
int N, K, S[1001];
pii O[1000];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;

		int num = 0, cnt = 0;
		for (int j = str.size() - 1; j >= 0 ; j--, cnt++) {
			if (str[j] == '1') num += (1 << cnt);
		}
		S[i] = num;
	}

	cin >> K;
	for (int i = 0; i < K; i++) {
		int n, d;
		cin >> n >> d;
		O[i] = { n , d };
	}
}

void changeS(int cur, int dir) {
	if (dir == -1) {
		if ((S[cur] & FirstBit) == FirstBit) S[cur] = ((S[cur] & SubFirstBit) << 1) + 1;
		else S[cur] <<= 1;
	}
	else {
		if ((S[cur] & 1) == 1) S[cur] = ((S[cur] >> 1) | FirstBit);
		else S[cur] >>= 1;
	}
}

void recur(int prev, int cur, int dir) {
	int n1 = cur - 1, n2 = cur + 1;
	int curS = S[cur];
	changeS(cur, dir);

	if (n1 != prev && n1 > 0) {
		int n1S = S[n1];

		bool curBitS = curS & (1 << 1);
		bool nextBitS = n1S & (1 << 5);

		if (curBitS != nextBitS) recur(cur, n1, dir == 1 ? -1 : 1);
	}
	if (n2 != prev && n2 <= N) {
		int n2S = S[n2];

		bool curBitS = curS & (1 << 5);
		bool nextBitS = n2S & (1 << 1);

		if (curBitS != nextBitS) recur(cur, n2, dir == 1 ? -1 : 1);
	}
}

void solve() {
	for (int i = 0; i < K; i++) {
		int n = O[i].first, dir = O[i].second;

		recur(n, n, dir);
	}
	
	int res = 0;
	for (int i = 1; i <= N; i++) {
		if ((S[i] & FirstBit) == FirstBit) res++;
	}
	cout << res;
}

int main() { //Åé´Ï¹ÙÄû (2)
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}