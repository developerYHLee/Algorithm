#include <iostream>
#include <cmath>

using namespace std;

int main() { //오르막길
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int l = 0, r = 0, res = 0;

	cin >> l;
	r = l;

	for (int i = 1; i < N; i++) {
		int n;
		cin >> n;

		if (r < n) r = n;
		else {
			l = n;
			r = n;
		}

		res = max(res, r - l);
	}

	cout << res;
}