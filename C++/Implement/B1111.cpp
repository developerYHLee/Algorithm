#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;
typedef pair<int, int> pii;

int main() { //IQ Test
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	bool check = true;
	vector<int> v(N);
	cin >> v[0];
	for (int i = 1; i < N; i++) {
		cin >> v[i];
		if (check) check = v[i - 1] == v[i];
	}
	if (N == 1) {
		cout << "A";
		return 0;
	}
	
	if (check) {
		cout << v[0];
		return 0;
	}

	if (N == 2) {
		cout << "A";
		return 0;
	}

	int o1 = v[1] - v[0], o2 = v[2] - v[1];
	if (o1 == 0) {
		cout << "B";
		return 0;
	}
	if (o2 % o1 != 0) {
		cout << "B";
		return 0;
	}

	int a = o2 / o1, b = -(a * v[0] - v[1]);

	for (int i = 3; i < N; i++) {
		if (a * v[i - 1] + b != v[i]) {
			cout << "B";
			return 0;
		}
	}

	cout << (v[N - 1] * a + b);
}