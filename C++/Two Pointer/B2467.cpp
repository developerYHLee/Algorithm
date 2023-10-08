#include <iostream>
#include <cmath>

using namespace std;

int num[100001];

inline void check(int& m, int& res_l, int& res_r, int temp, int l, int r) {
	if (m > abs(temp)) {
		m = abs(temp);
		res_l = num[l];
		res_r = num[r];
	}
}

int main() { //ฟ๋พื
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) cin >> num[i];

	int l = 0, r = N - 1, m = 2e9;
	int res_l = 0, res_r = 0;
	while (l < r) {
		int temp = num[l] + num[r];

		if (temp == 0) {
			res_l = num[l];
			res_r = num[r];
			break;
		}
		else if (temp > 0) {
			check(m, res_l, res_r, temp, l, r);
			r--;
		}
		else {
			check(m, res_l, res_r, temp, l, r);
			l++;
		}
	}

	cout << res_l << " " << res_r;
}