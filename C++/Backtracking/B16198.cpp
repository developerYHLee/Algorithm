#include <iostream>
#include <vector>

using namespace std;

int N, res;
vector<int> W;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int w;
		cin >> w;

		W.push_back(w);
	}
}

void recur(int cmp) {
	if (W.size() == 2) {
		res = max(res, cmp);
		return;
	}

	int sz = W.size() - 1;
	for (int i = 1; i < sz; i++) {
		int w = W[i];
		W.erase(W.begin() + i);
		recur(cmp + W[i] * W[i - 1]);
		W.insert(W.begin() + i, w);
	}
}

void solve() {
	recur(0);
	cout << res;
}

int main() { //에너지 모으기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}