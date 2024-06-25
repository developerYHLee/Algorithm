#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
typedef pair<int, int> pii;

int N;
pii arr[1'000'000];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
}

void solve() {
	sort(arr, arr + N);

	int res = 0, l = INT_MIN, r = INT_MIN;
	for (int i = 0; i < N; i++) {
		if (r < arr[i].first) {
			res += r - l;
			l = arr[i].first;
			r = arr[i].second;
		}
		else if (r < arr[i].second) r = arr[i].second;
	}
	res += r - l;
	cout << res;
}

int main() { //¼± ±ß±â
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}