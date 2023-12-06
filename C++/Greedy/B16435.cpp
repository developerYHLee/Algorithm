#include <iostream>
#include <algorithm>

using namespace std;

int h[1000];
int main() { //스네이크버드
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, L;
	cin >> N >> L;

	for (int i = 0; i < N; i++) cin >> h[i];
	sort(h, h + N);

	for (int i = 0; i < N; i++) {
		if (L + i < h[i]) {
			cout << L + i;
			return 0;
		}
	}

	cout << L + N;
}