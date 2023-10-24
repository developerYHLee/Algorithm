#include <iostream>
#include <algorithm>

using namespace std;

int main() { //น่
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int* crane = new int[N] {};
	for (int i = 0; i < N; i++) cin >> crane[i];

	int M;
	cin >> M;

	bool* vis = new bool[M] {};
	int* box = new int[M] {};
	for (int i = 0; i < M; i++) cin >> box[i];

	sort(crane, crane + N, greater());
	sort(box, box + M, greater());

	if (crane[0] < box[0]) {
		cout << -1;
		return 0;
	}

	int res = 0, count = 0;
	while (count < M) {
		res++;

		int index = 0;
		for (int i = 0; i < N; i++) {
			for (; index < M; index++) {
				if (vis[index] || crane[i] < box[index]) continue;
				
				vis[index++] = true;
				count++;
				break;
			}
		}
	}
	
	cout << res;
}