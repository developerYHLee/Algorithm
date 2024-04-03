#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

string str;
vector<int> D;

void input() { cin >> str; }

bool check(int& p, char c) {
	for (int i = p; i < D.size(); i++) {
		if (c == 'u') {
			if (D[i] == 1) {
				D[i]++;
				return true;
			}
		}
		else if (c == 'a') {
			if (D[i] == 2) {
				D[i]++;
				return true;
			}
		}
		else if (c == 'c') {
			if (D[i] == 3) {
				D[i]++;
				return true;
			}
		}
		else if (c == 'k') {
			if (D[i] == 4) {
				D[i]++;
				p++;
				return true;
			}
		}
	}

	return false;
}
void solve() {
	int p = 0, res = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'q') D.push_back(1);
		else {
			if (!check(p, str[i])) {
				cout << -1;
				return;
			}
		}

		res = max(res, (int)D.size() - p);
	}

	if (D.size() == p) cout << res;
	else cout << -1;
}

int main() { //¿À¸®
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}