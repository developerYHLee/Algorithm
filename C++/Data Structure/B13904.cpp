#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

bool cmp(pii o1, pii o2) {
	if (o1.first == o2.first) return o1.second > o2.second;
	return o1.first < o2.first;
}

int N;
vector<pii> work;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int d, w;
		cin >> d >> w;

		work.push_back({ d, w });
	}

	sort(work.begin(), work.end(), cmp);
}

void solve() {
	priority_queue<int, vector<int>, greater<int>> PQ;

	int res = 0;
	for (int i = 0; i < N; i++) {
		int d = work[i].first, w = work[i].second;

		if (PQ.size() < d) {
			res += w;
			PQ.push(w);
		}
		else if (PQ.size() == d && PQ.top() < w) {
			res -= PQ.top();
			PQ.pop();

			res += w;
			PQ.push(w);
		}
	}

	cout << res;
}

int main() { //°úÁ¦
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}