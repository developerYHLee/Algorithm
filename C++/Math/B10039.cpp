#include <iostream>

using namespace std;

int main() { //��� ����
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int sum = 0;
	for (int i = 0; i < 5; i++) {
		int score;
		cin >> score;
		sum += score < 40 ? 40 : score;
	}

	cout << sum / 5;
}