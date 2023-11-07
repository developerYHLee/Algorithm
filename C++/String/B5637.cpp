#include <iostream>
#include <algorithm>
#include <regex>
#include <string>

using namespace std;

int main() { //가장 긴 단어
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	regex pattern("([a-zA-Z-]+)");
	string string_max = "";
	int MAX = 0;
	while (true) {
		string str;
		cin >> str;
		
		auto words_begin = sregex_iterator(str.begin(), str.end(), pattern);
		auto words_end = sregex_iterator();

		for (auto i = words_begin; i != words_end; i++) {
			smatch match = *i;

			if (match.str().compare("E-N-D") == 0) {
				transform(string_max.begin(), string_max.end(), string_max.begin(), [](char c) {return tolower(c); });
				cout << string_max;
				return 0;
			}

			if (match.str().size() > MAX) {
				MAX = match.str().size();
				string_max = match.str();
			}
		}
	}
}