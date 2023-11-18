#include <iostream>

using namespace std;

int main() { //카드 게임
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int n;
		cin >> n;

		sum += n;
	}

	cout << sum;
}