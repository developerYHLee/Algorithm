#include <iostream>
#include <cmath>

using namespace std;

int main() { //��ٳ���
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int burger = 10000;
	for (int i = 0; i < 3; i++) {
		int b;
		cin >> b;

		burger = min(burger, b);
	}

	int coke = 10000;
	for (int i = 0; i < 2; i++) {
		int c;
		cin >> c;

		coke = min(coke, c);
	}

	cout << burger + coke - 50;
}