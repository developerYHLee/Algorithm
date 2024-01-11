#include <iostream>

using namespace std;

int main() { //º° Âï±â - 12
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i < N; i++) {
		for (int j = N; j > i; j--) cout << " ";
		for (int j = 0; j < i; j++) cout << "*";
		cout << "\n";
	}
	for (int i = 0; i < N; i++) cout << "*";
	cout << "\n";
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) cout << " ";
		for (int j = N; j > i; j--) cout << "*";
		cout << "\n";
	}
}