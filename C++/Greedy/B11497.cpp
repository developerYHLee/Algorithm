#include <iostream>
#include <algorithm>

using namespace std;

int h[10000];
int main() { //통나무 건너뛰기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T-- > 0) {
		int N;
		cin >> N;

		for (int i = 0; i < N; i++) cin >> h[i];
		sort(h, h + N, greater<int>());

		int res = max(h[N - 2] - h[N - 1], max(h[0] - h[1], h[0] - h[2]));
		for (int i = 1; i < N - 2; i++) res = max(res, h[i] - h[i + 2]);
	
		cout << res << '\n';
	}
}