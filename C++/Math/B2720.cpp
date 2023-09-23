#include <iostream>

using namespace std;

inline int get_count(int m, int c) { return m / c; }

int main() { //¼¼Å¹¼Ò »çÀå µ¿Çõ
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T-- > 0) {
		int coins[4]{ 25, 10, 5, 1 };

		int m;
		cin >> m;

		for (int i = 0; i < 4; i++) {
			int num = m / coins[i];
			m -= num * coins[i];
			cout << num << " ";
		}

		cout << endl;
	}
}