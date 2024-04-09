#include <iostream>
#include <vector>

using namespace std;

const int MAX = 8;
int index = -1;
string str;
vector<string> P, res;

void input() { cin >> str; }

void setRes() {
	string temp = "";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ':') {
			if (temp.length() == 0) {
				if (index == -1) index = P.size();
			}
			else P.push_back(temp);
			temp = "";
		}
		else temp += str[i];
	}
	if (temp.length() > 0) P.push_back(temp);
}

void check(int cnt) {
	for (int i = 0; i < cnt; i++) res.push_back("0000");
}

void getOriginal() {
	int cnt = 0;
	for (int i = 0; i < MAX;) {
		if (i == index) {
			cnt = MAX - P.size();
			check(cnt);
			i += cnt;
		}
		else {
			string temp = "";
			int sz = 4 - P[i - cnt].length();
			for (int j = 0; j < sz; j++) temp += "0";
			temp += P[i - cnt];
			res.push_back(temp);
			i++;
		}
	}
}

void solve() {
	setRes();
	getOriginal();
	for (int i = 0; i < 7; i++) cout << res[i] << ":";
	cout << res[7];
}

int main() { //IPv6
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}