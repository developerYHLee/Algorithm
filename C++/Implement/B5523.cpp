#include <iostream>

using namespace std;

int N, A, B;

int main() { //경기 결과
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	while (N--) {
		int a, b;
		cin >> a >> b;

		a > b ? A++ : a < b ? B++ : 0;
	}
	cout << A << " " << B;
}