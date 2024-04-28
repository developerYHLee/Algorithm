#include <iostream>
#include <unordered_map>

using namespace std;
typedef long long ll;

unordered_map<ll, ll> M;
ll N;
int P, Q;

void input() {
	cin >> N;
	cin >> P;
	cin >> Q;
}

ll recur(ll i) {
	if (!i) return 1;
	if (M.find(i) != M.end()) return M[i];

	return M[i] = recur(i / P) + recur(i / Q);
}

void solve() {
	cout << recur(N);
}

int main() { //무한 수열
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}