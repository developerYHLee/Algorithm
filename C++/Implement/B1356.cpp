#include <iostream>

using namespace std;

string str;

int main() { //À¯Áø¼ö
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> str;

	if (str.size() == 1) {
		cout << "NO";
		return 0;
	}

	for (int i = 0; i < str.size(); i++) {
		int n1 = 1, n2 = 1;

		for (int j = 0; j <= i; j++) n1 *= str[j] - '0';
		for (int j = i + 1; j < str.size(); j++) n2 *= str[j] - '0';

		if (n1 == n2) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}