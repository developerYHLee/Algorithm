#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

string my_plus(string o1, string o2) {
	string ret = "";

	if (o1.size() < o2.size()) swap(o1, o2);

	bool p = false;
	int i1 = o1.size() - 1, i2 = o2.size() - 1;
	while (i2 >= 0) {
		int n = o1[i1] - '0' + o2[i2] - '0';

		if (p) n++;
		p = false;

		if (n > 9) {
			n %= 10;
			p = true;
		}

		ret += n + '0';
		i1--;
		i2--;
	}

	while (i1 >= 0) {
		int n = o1[i1] - '0';

		if (p) n++;
		p = false;

		if (n > 9) {
			n %= 10;
			p = true;
		}

		ret += n + '0';
		i1--;
	}

	if (p) ret += "1";

	reverse(ret.begin(), ret.end());
	return ret;
}

char solve() {
	int N;
	cin >> N;

	string str;
	cin >> str;
	N--;

	string p = "0", m = "0";
	if (str[0] == '-') m = str.substr(1);
	else p = str;

	while (N-- > 0) {
		string temp;
		cin >> temp;

		if (temp[0] == '-') m = my_plus(m, temp.substr(1));
		else p = my_plus(p, temp);
	}

	if (p.size() < m.size()) return '-';
	else if (p.size() > m.size()) return '+';
	else {
		for (int i = 0; i < p.size(); i++) {
			if (p[i] == m[i]) continue;
			else if (p[i] > m[i]) return '+';
			else return '-';
		}

		return '0';
	}
}

int main() { //∫Œ»£
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 3; i++) cout << solve() << endl;
}