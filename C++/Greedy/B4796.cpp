#include <iostream>

using namespace std;

int main() { //д╥гн
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int L, P, V;
	cin >> L >> P >> V;

	int i = 1;
	while (L > 0) {
		cout << "Case " << i++ << ": " << (V / P * L + (V % P > L ? L : V % P)) << '\n';
		cin >> L >> P >> V;
	}
}