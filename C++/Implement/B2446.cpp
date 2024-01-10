#include <iostream>

using namespace std;

int main() { //º° Âï±â - 9
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = N; i > 0; i--) {
		for (int j = N; j > i; j--) cout << " ";
		for (int j = i * 2; j > 1; j--) cout << "*";
		cout << "\n";
	}
	for (int i = 2; i <= N; i++) {
		for (int j = N; j > i; j--) cout << " ";
		for (int j = i * 2; j > 1; j--) cout << "*";
		cout << "\n";
	}
}