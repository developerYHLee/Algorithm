#include <iostream>

using namespace std;

int main() { //¼¼ ¼ö
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	if (a + b == c) cout << a << "+" << b << "=" << c;
	else if (a - b == c) cout << a << "-" << b << "=" << c;
	else if (a * b == c) cout << a << "*" << b << "=" << c;
	else if (a / b == c) cout << a << "/" << b << "=" << c;
	else if (b + c == a) cout << a << "=" << b << "+" << c;
	else if (b - c == a) cout << a << "=" << b << "-" << c;
	else if (b * c == a) cout << a << "=" << b << "*" << c;
	else if (b / c == a) cout << a << "=" << b << "/" << c;
}