#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int> vi;

int N, C, arr[30];
vi L, R;

void input() {
	cin >> N >> C;
	for (int i = 0; i < N; i++) cin >> arr[i];
}

void recur(int index, int lastIndex, int sum, vi &temp) {
	if (sum > C || index == lastIndex) return;

	if (sum + arr[index] <= C) {
		temp.push_back(sum + arr[index]);
		recur(index + 1, lastIndex, sum + arr[index], temp);
	}
	recur(index + 1, lastIndex, sum, temp);
}

int getRes() {
	sort(R.begin(), R.end());

	int ret = L.size() + R.size();

	for (int i = 0; i < L.size(); i++) {
		int key = C - L[i];

		auto u = upper_bound(R.begin(), R.end(), key);
		ret += u - R.begin();
	}

	return ret + 1;
}

void solve() {
	recur(0, N / 2, 0, L);
	recur(N / 2, N, 0, R);
	cout << getRes();
}

int main() { //³À»ö¹®Á¦
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}