#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() { //단어 나누기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	string res = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";

	for (int i = 1; i < str.size(); i++) {
		for (int j = 1; i + j < str.size(); j++) {
			string str1 = str.substr(0, i);
			string str2 = str.substr(i, j);
			string str3 = str.substr(i + j, str.size() - (i + j));

			reverse(str1.begin(), str1.end());
			reverse(str2.begin(), str2.end());
			reverse(str3.begin(), str3.end());

			string temp = str1 + str2 + str3;
			
			if (res.compare(temp) > 0) res = temp;

		}
	}

	cout << res;
}