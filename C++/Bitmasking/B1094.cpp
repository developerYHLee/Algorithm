#include <iostream>

using namespace std;

int main() { //¸·´ë±â
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int X, res = 0;
	cin >> X;

	for (int i = 6; X > 0; i--) {
		if ((1 << i) <= X) {
			X -= (1 << i);
			res++;
		}
	}

	cout << res;
}