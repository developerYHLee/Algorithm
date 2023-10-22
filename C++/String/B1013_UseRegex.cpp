#include <iostream>
#include <regex>

using namespace std;

int main() { //Contact (Use Regex) 
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T-- > 0) {
		string str;
		cin >> str;

		regex pattern("(100+1+|01)+");
		cout << (regex_match(str, pattern) ? "YES\n" : "NO\n");
	}
}