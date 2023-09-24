#include <iostream>
#include <cmath>

using namespace std;

int main() { //진법 변환
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	int B;
	cin >> str >> B;

	int sum = 0, size = str.length() - 1;
	for (int i = size; i >= 0; i--) {
		char c = str[i];

		int temp = 0;
		if (c >= 'A' && c <= 'Z') temp = c - 'A' + 10;
		else temp = c - '0';

		sum += temp * pow(B, size - i);
	}

	cout << sum;
}