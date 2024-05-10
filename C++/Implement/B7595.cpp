#include <iostream>

using namespace std;

void printTriangles(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) cout << "*";
		cout << "\n";
	}
}

int main() { //Triangles
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	while (N) {
		printTriangles(N);
		cin >> N;
	}
}