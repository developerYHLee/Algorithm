#include <iostream>

using namespace std;

int main() { //È¦¼ö
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int sum = 0, m = 1e9;
	for (int i = 0; i < 7; i++) {
		int n;
		cin >> n;
		
		if (n % 2 != 0) {
			sum += n;
			m = min(m, n);
		}
	}

	if (m == 1e9) cout << -1;
	else cout << sum << "\n" << m;
}