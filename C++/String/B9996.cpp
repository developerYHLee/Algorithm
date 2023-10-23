#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() { //한국이 그리울 땐 서버에 접속하지
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	string s;
	cin >> s;
	s.replace(s.find('*'), 1, "\\w*");

	while (T-- > 0) {
		string str;
		cin >> str;

		regex re(s);
		cout << (regex_match(str, re) ? "DA\n" : "NE\n");
	}
}