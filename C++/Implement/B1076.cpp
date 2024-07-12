#include <iostream>
#include <cmath>

using namespace std;

int checkColor(const string& str) {
	if (str.compare("black") == 0) return 0;
	else if (str.compare("brown") == 0) return 1;
	else if (str.compare("red") == 0) return 2;
	else if (str.compare("orange") == 0) return 3;
	else if (str.compare("yellow") == 0) return 4;
	else if (str.compare("green") == 0) return 5;
	else if (str.compare("blue") == 0) return 6;
	else if (str.compare("violet") == 0) return 7;
	else if (str.compare("grey") == 0) return 8;
	else if (str.compare("white") == 0) return 9;
}

int main() { //ÀúÇ×
	long long res = 0;

	for (int i = 0; i < 2; i++) {
		string str;
		cin >> str;

		res *= 10;
		res += checkColor(str);
	}

	string str;
	cin >> str;

	res *= pow(10, checkColor(str));
	cout << res;
}