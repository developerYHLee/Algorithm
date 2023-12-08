#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int t[10000];
int main() { //ÄÜ¼¾Æ®
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) cin >> t[i];
	sort(t, t + N, greater<int>());

	int res = 0;
	priority_queue<int, vector<int>, greater<int>> PQ;
	for (int i = 0; i < N; i++) {
		PQ.push(res + t[i]);

		if (PQ.size() >= M) {
			res = PQ.top();
			PQ.pop();

			while (!PQ.empty()) {
				int cur = PQ.top();

				if (cur > res) break;
				PQ.pop();
			}
		}
	}

	while (!PQ.empty()) {
		res = PQ.top();
		PQ.pop();
	}

	cout << res;
}