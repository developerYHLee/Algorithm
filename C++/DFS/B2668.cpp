#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> res;
int num[101], N;
bool ch[101], used[101];

void input() {
	cin >> N;

	for (int i = 1; i <= N; i++) cin >> num[i];
}

void recur(int n) {
	if (used[num[n]]) return;
	else {
		if (ch[num[n]]) {
			used[num[n]] = true;
			res.push_back(num[n]);
		}
		ch[num[n]] = true;
		recur(num[n]);
		ch[num[n]] = false;
	}
}

void solve() {
	for (int i = 1; i <= N; i++) {
		if (!used[i]) recur(i);
	}

	sort(res.begin(), res.end());
	cout << res.size() << "\n";
	for (int i : res) cout << i << "\n";
}

int main() { //숫자고르기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}