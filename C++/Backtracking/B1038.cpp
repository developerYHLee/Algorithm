#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

const ll MAX = 9999999999;
ll res[1000001];
int cnt, N;

void input() {
	cin >> N;
	fill_n(res, 1000001, MAX);
}

void recur(ll num) {
	res[cnt++] = num;

	for (int i = 0; i <= 9; i++) {
		if (i >= num % 10) return;
		recur(num * 10 + i);
	}
}

void solve() {
	for (int i = 0; i <= 9; i++) recur(i);
	sort(res, res + 1000001);
	cout << (res[N] == MAX ? -1 : res[N]);
}

int main() { //감소하는 수
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}