#include <iostream>

using namespace std;

int main() { //Fill the Rowboats!
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int i = 1;
	for (; i <= N; i++) {
		cout << i << " ";
		if (i % 6 == 0) cout << "Go! ";
	}
	if (i % 6 != 1) cout << "Go!";
}