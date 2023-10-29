#include <iostream>
#include <cmath>

using namespace std;

int main() { //최소, 최대 2
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T-- > 0) {
		int big = -1e9, small = 1e9;
		
		int N;
		cin >> N;
		
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;

			big = max(big, num);
			small = min(small, num);
		}

		cout << small << " " << big << endl;
	}
}