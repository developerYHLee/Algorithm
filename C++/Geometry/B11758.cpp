#include <iostream>

using namespace std;

struct pos {
	int x, y;
};
pos a;
int main() { //CCW
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	pos a, b, c;
	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> c.x >> c.y;

	int S = (a.x * b.y + b.x * c.y + c.x * a.y) - (b.x * a.y + c.x * b.y + a.x * c.y);
	cout << (S == 0 ? 0 : S > 0 ? 1 : -1);
}