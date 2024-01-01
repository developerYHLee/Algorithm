#include <iostream>

using namespace std;

int N;

void print_star(int i) {
	for (int j = 0; j < i; j++) cout << "*";
}

void print_blank(int i) {
	for (int j = N; j > i; j--) cout << " ";
}

int main() { //º° Âï±â - 8
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i < N; i++) {
		print_star(i);
		print_blank(i);
		print_blank(i);
		print_star(i);
		cout << '\n';
	}
	for (int i = 0; i < N * 2; i++) cout << "*";
	cout << '\n';
	for (int i = N - 1; i >= 1; i--) {
		print_star(i);
		print_blank(i);
		print_blank(i);
		print_star(i);
		cout << '\n';
	}
}