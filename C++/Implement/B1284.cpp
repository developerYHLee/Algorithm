#include <iostream>

using namespace std;

int solve(int num) {
	int ret = 1;

	while (num > 0) {
		int temp = num % 10;
		num /= 10;

		if (temp == 1) ret += 3;
		else if (temp == 0) ret += 5;
		else ret += 4;
	}

	return ret;
}

int main() { //Áý ÁÖ¼Ò
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	while (N) {
		cout << solve(N) << '\n';
		cin >> N;
	}
}