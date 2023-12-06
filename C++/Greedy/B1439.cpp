#include<iostream>

using namespace std;

int main() { //µÚÁý±â
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	int one = str[0] == '1', zero = str[0] == '0';
	for (int i = 1; i < str.size(); i++) {
		if (str[i] != str[i - 1]) {
			one += str[i] == '1';
			zero += str[i] == '0';
		}
	}

	cout << (one > zero ? zero : one);
}