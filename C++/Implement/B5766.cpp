#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef pair<int, int> pii;

pii _count[10001];

int main() { //할아버지는 유명해!
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	while (true) {
		if (N == 0 && M == 0) break;
	
		for (int i = 0; i <= 10000; i++) _count[i] = { 0, i };
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int r;
				cin >> r;

				_count[r].first++;
			}
		}

		sort(_count, _count + 10000, [](pii o1, pii o2) {
			if (o1.first == o2.first) return o1.second < o2.second;
			return o1.first > o2.first;
		});

		int r = _count[1].first;
		for (int i = 1; i <= 10000; i++) {
			if (_count[i].first != r) break;

			cout << _count[i].second << " ";
		}
		cout << endl;

		cin >> N >> M;
	}
}