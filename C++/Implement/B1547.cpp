#include <iostream>

using namespace std;

int cup[4];
int main() { //°ø
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 1; i <= 3; i++) cup[i] = i;

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int c1, c2;
		cin >> c1 >> c2;

		int a = 0, b = 0;
		for (int j = 1; j <= 3; j++) {
			if (cup[j] == c1) a = j;
			if (cup[j] == c2) b = j;
		}

		swap(cup[a], cup[b]);
	}

	cout << cup[1];
}