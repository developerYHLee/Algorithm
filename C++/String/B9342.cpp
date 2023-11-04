#include <iostream>
#include <regex>

using namespace std;

int main() { //¿°»öÃ¼
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	regex re(R"([A-F]?A+F+C+[A-F]?)");
	while (T-- > 0) {
		string str;
		cin >> str;

		cout << (regex_match(str, re) ? "Infected!\n" : "Good\n");
	}
}