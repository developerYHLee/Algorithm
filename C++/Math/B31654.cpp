#include <iostream>

using namespace std;

int main() { //Adding Trouble
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, c;
	cin >> a >> b >> c;

	cout << (a + b == c ? "correct!" : "wrong!");
}