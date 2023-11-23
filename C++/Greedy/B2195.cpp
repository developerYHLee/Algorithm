#include <iostream>
#include <algorithm>

using namespace std;

int res[1001];
int main() { //문자열 복사
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string S, P;
	cin >> S >> P;
	
	fill_n(res, 1001, 1e9);
	res[0] = 0;

	for (int i = 0; i < P.size(); i++) {
		int cnt = 0, m = res[i] + 1, s_i = i + 1;

		for (int j = 0; j < S.size(); j++) {
			if (P[i + cnt] != S[j]) {
				if (cnt > 0) cnt = 0;
			}
			else {
				res[s_i + cnt] = min(res[s_i + cnt], m);
				cnt++;
			}
		}
	}

	cout << res[P.size()];
}