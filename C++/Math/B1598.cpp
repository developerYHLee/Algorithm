#include <iostream>
#include <cmath>

using namespace std;

int main() { //꼬리를 무는 숫자 나열
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n1, n2;
	cin >> n1 >> n2;

	int r1 = --n1 % 4, r2 = --n2 % 4;
	int c1 = n1 / 4, c2 = n2 / 4;
	
	cout << abs(r1 - r2) + abs(c1 - c2);
}