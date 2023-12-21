#include <iostream>

using namespace std;

int main() { //ÇÃ·¯±×
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, res;
	cin >> N >> res;

	for (int i = 1; i < N; i++) {
		int num;
		cin >> num;

		res += num - 1;
	}

	cout << res;
}