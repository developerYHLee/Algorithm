#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, arr[1'000'000];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
}

void solve() {
	vector<int> S;
	for (int i = 0; i < N; i++) {
		auto iter = lower_bound(S.begin(), S.end(), arr[i]);

		if (iter == S.end()) S.push_back(arr[i]);
		else S[iter - S.begin()] = arr[i];
	}
	cout << S.size();
}

int main() { //가장 긴 증가하는 부분 수열 2
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}