#include <iostream>
#include <string>

using namespace std;

int main() { //A¿Í B
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string S, T;
	cin >> S >> T;

	int N = S.size();
	int l = 0, r = T.size() - 1, p = r;
	while (r - l + 1 != N) {
		if (T[p] == 'A') {
			if (p == l) {
				l++;
				p = l;
			}
			else {
				r--;
				p = r;
			}
		}
		else {
			if (p == l) {
				l++;
				p = r;
			}
			else {
				r--;
				p = l;
			}
		}
	}

	string res = "";
	if (p == r) {
		for (int i = l; i <= r; i++) res += T[i];
	}
	else {
		for (int i = r; i >= l; i--) res += T[i];
	}

	if (res.compare(S) == 0) cout << 1;
	else cout << 0;
}