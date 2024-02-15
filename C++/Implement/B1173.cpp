#include <iostream>

using namespace std;

int main() { //¿îµ¿
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, m, M, T, R, res = 0;
	cin >> N >> m >> M >> T >> R;

	int cur = m;
	if (cur + T > M) {
		cout << -1;
		return 0;
	}

	while (N > 0) {
		res++;
		if (cur + T > M) {
			cur -= R;
			
			if (cur < m) cur = m;
		}
		else {
			cur += T;
			N--;
		}
	}

	cout << res;
}