#include <iostream>
#include <memory.h>
#include <cmath>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

const int MAXBIT = 1 << 10;
int seat[11], dp[11][MAXBIT], N, M, res;
vpii line;

void makeLine(int index, int bit, int cnt) {
	if (index >= M) {
		line.push_back({ bit, cnt });
		return;
	}

	makeLine(index + 2, bit | (1 << index), cnt + 1);
	makeLine(index + 1, bit, cnt);
}

void input() {
	memset(dp, 0, sizeof(dp));
	memset(seat, 0, sizeof(seat));
	line.clear();

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < M; j++) {
			if (str[j] == 'x') seat[i] |= (1 << j);
		}
	}

	makeLine(0, 0, 0);
}

bool checkBit(int curBit, int prevBit) {
	if ((curBit >> 1) & prevBit) return false;
	if ((curBit << 1) & prevBit) return false;

	return true;
}

void solve() {
	int res = 0;

	for (int i = 1; i <= N; i++) {
		for (pii curL : line) {
			int bit = curL.first, cnt = curL.second;

			if (bit & seat[i]) continue;
			
			for (pii prevL : line) {
				if (!checkBit(bit, prevL.first)) continue;

				dp[i][bit] = max(dp[i][bit], dp[i - 1][prevL.first] + cnt);
				res = max(res, dp[i][bit]);
			}
		}
	}

	cout << res << "\n";
}

int main() { //да╢в
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T-- > 0) {
		input();
		solve();
	}
}