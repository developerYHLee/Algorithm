#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

int N, arr[4000][4];
vi L, R;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
}

void setLeftRight() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			L.push_back(arr[i][0] + arr[j][1]);
			R.push_back(arr[i][2] + arr[j][3]);
		}
	}
	sort(R.begin(), R.end());
}

ll getRes() {
	ll ret = 0;
	
	int p = 0;
	while (p < L.size()) {
		int rP = p, key = L[p];

		while (++rP < L.size()) if (L[rP] != key) break;
		
		auto l = lower_bound(R.begin(), R.end(), -key);
		auto r = upper_bound(R.begin(), R.end(), -key);
	
		ret += (rP - p) * (r - l);

		p = rP;
	}

	return ret;
}

void solve() {
	setLeftRight();
	cout << getRes();
}

int main() { //합이 0인 네 정수
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}