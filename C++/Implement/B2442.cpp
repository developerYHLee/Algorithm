#include <iostream>

using namespace std;

int main() { //º° Âï±â - 5
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = N; j > i; j--) cout << " ";
		for (int j = 0; j < 2 * i - 1; j++) cout << "*";
		cout << '\n';
	}
}