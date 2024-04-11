#include <iostream>

using namespace std;

int main() { //µ¹ °ÔÀÓ 6
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long N;
	cin >> N;
	cout << ((N % 7 == 0 || N % 7 == 2) ? "CY" : "SK");
}