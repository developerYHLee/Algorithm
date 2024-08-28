#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll res;
int N, S, arr[40];
vector<int> L, R;

void input() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> arr[i];
}

void recur(int index, int lastIndex, int sum, vector<int>& temp) {
	if (index == lastIndex) return;
	
	if (sum + arr[index] == S) res++;
	temp.push_back(sum + arr[index]);
	
	recur(index + 1, lastIndex, sum + arr[index], temp);
	recur(index + 1, lastIndex, sum, temp);
}

void getP(int& lP, int& rP, int& sz, int key) {
	while (rP < L.size() && L[rP] == key) rP++;
	sz = rP - lP;
}

void getRes() {
	sort(L.begin(), L.end());
	sort(R.begin(), R.end());

	int lP = 0;
	while (lP < L.size()) {
		int rP = lP, key = L[rP], sz = 0;

		getP(lP, rP, sz, key);

		auto l = lower_bound(R.begin(), R.end(), S - key);
		auto u = upper_bound(R.begin(), R.end(), S - key);
		
		res += (ll)sz * (u - l);

		lP = rP;
	}
}

void solve() {
	recur(0, N / 2, 0, L);
	recur(N / 2, N, 0, R);
	getRes();
	cout << res;
}

int main() { //부분수열의 합 2
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}