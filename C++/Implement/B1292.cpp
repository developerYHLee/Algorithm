#include <iostream>

using namespace std;

int main() { //쉽게 푸는 문제
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int A, B;
	cin >> A >> B;

	int res = 0, index = 1;
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= i; j++) {
			if (index >= A && index <= B) res += i;
			index++;
		}
	}

	cout << res;
}