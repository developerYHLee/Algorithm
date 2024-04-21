#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;

set<ll> S;
int N;
ll A[100], res[100];

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		S.insert(A[i]);
	}
}

bool dfs(int cnt, ll x) {
	res[cnt] = x;

	if (cnt == N - 1) {
		for (int i = 0; i < N; i++) cout << res[i] << " ";
		return true;
	}

	if (S.find(x * 2) != S.end()) {
		if (dfs(cnt + 1, x * 2)) return true;
	}
	if (x % 3 == 0 && S.find(x / 3) != S.end()) {
		if (dfs(cnt + 1, x / 3)) return true;
	}

	return false;
}

void solve() {
	for (int i = 0; i < N; i++) {
		if (dfs(0, A[i])) return;
	}
}

int main() { //³ª3°ö2
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}