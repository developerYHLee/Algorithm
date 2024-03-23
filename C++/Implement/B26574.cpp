#include <iostream>

using namespace std;

int main() { //Copier
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		cout << n << " " << n << "\n";
	}
}