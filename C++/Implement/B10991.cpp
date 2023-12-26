#include <iostream>

using namespace std;

int main() { //º° Âï±â - 16
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - i - 1; j++) cout << " ";
		cout << "*";
		for (int j = N - i; j < N; j++) cout << " *";
		cout << '\n';
	}
}