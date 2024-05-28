#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int N;

void input() {
	while (cin >> N) {
		vector<int> V;
		for (int i = 0; i < N; i++) {
			int n;
			cin >> n;

			auto iter = lower_bound(V.begin(), V.end(), n);
			if (iter == V.end()) V.push_back(n);
			else V[iter - V.begin()] = n;
		}

		cout << V.size() << "\n";
		cin.ignore();
	}
}

int main() { //¿À¸§¼¼
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
}