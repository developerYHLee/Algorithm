#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, Q;
vector<int> R, B;
string S;

void input() {
	cin >> N >> Q >> S;
}

void setRB() {
	for (int i = 0; i < N; i++) {
		if (S[i] == 'R') R.push_back(i);
		else if (S[i] == 'B') B.push_back(i);
	}
}

void solve() {
	setRB();

	for (int i = 0; i < Q; i++) {
		int l, r;
		cin >> l >> r;

		int a = lower_bound(R.begin(), R.end(), l) - R.begin();
		int b = a + 1;

		if (b >= R.size() || R[b] > r) {
			cout << -1 << "\n";
			continue;
		}

		int c = upper_bound(B.begin(), B.end(), R[b]) - B.begin();
		int d = c + 1;

		if (d >= B.size() || B[d] > r) {
			cout << -1 << "\n";
			continue;
		}

		cout << R[a] << " " << R[b] << " " << B[c] << " " << B[d] << "\n";
	}
}

int main() { //»¡°­~ »¡°­~ ÆÄ¶û! ÆÄ¶û! ´ÞÄÞÇÑ ¼Ø»çÅÁ!
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}