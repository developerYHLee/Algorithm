#include <iostream>
#include <cmath>

using namespace std;

int main() { //우리집엔 도서관이 있어
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int MAX = 0, res = 0;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		MAX = max(MAX, num);
		if (num < MAX) res = max(res, num);
	}

	cout << res;
}