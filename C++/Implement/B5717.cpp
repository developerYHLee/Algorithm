#include <iostream>

using namespace std;

int main() { //������� ģ����
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int M, F;
	cin >> M >> F;

	while (M || F) {
		cout << M + F << "\n";
		cin >> M >> F;
	}
}