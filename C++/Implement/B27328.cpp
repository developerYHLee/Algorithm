#include <iostream>

using namespace std;

int main() { //߲۰���� (Three-Way Comparison)
	int A, B;
	cin >> A >> B;
	cout << (A == B ? 0 : A > B ? 1 : -1);
}