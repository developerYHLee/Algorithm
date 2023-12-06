#include <iostream>

using namespace std;
typedef long long ll;

ll make_S(ll num) {
	return num * (num + 1) / 2;
}

int main() { //수들의 합
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll S;
	cin >> S;

	int i = 1;
	while (true) {
		if (make_S(i) > S) {
			cout << i - 1;
			return 0;
		}

		i++;
	}
}