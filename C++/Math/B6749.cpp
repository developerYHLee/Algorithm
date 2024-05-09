#include <iostream>

using namespace std;

int main() { //Next in line
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int Y, M;
	cin >> Y >> M;
	cout << 2 * M - Y;
}