#include <iostream>
#include <cmath>

using namespace std;

int main() { //ÑÑøÁÓØ (Konpeito)
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int A, B, C;
	cin >> A >> B >> C;

	int M = A > B ? (A > C ? A : C) : (B > C ? B : C);
	cout << 3 * M - A - B - C;
}