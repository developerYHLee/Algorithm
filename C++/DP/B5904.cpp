#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> dp;

void input() {
	cin >> N;

	dp.push_back(3);
	int temp = 1;
	while (dp[dp.size() - 1] < N) dp.push_back(dp[dp.size() - 1] * 2 + dp.size() + 3);
}

bool check(int m) {
	if (N <= m) {
		if (N == 1) cout << "m";
		else cout << "o";
		return true;
	}
	return false;
}

void solve() {
	int index = dp.size() - 1;
	while (index) {
		int cnt = dp[index - 1], m = dp[index] - cnt * 2;
		
		if (N <= cnt) {
			index--;
			continue;
		}

		N -= cnt;
		if (check(m)) return;

		N -= m;
		index--;
	}
	check(3);
}

int main() { //Moo °ÔÀÓ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}