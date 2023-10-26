#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> o1, vector<int> o2) {
	if (o1[0] == o2[0]) return o1[1] < o2[1];
	return o1[0] < o2[0];
}

vector<vector<int>> t;
int main() { //°­ÀÇ½Ç
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	t.resize(N, vector<int>());
	for (int i = 0; i < N; i++) {
		int n, s, e;
		cin >> n >> s >> e;

		t[i].push_back(s);
		t[i].push_back(e);
	}
	sort(t.begin(), t.end(), cmp);

	priority_queue<int, vector<int>, greater<int>> PQ;
	int res = 1;
	PQ.push(t[0][1]);

	for (int i = 1; i < N; i++) {
		int next = t[i][0], cur = PQ.top();

		while (next >= cur) {
			PQ.pop();

			if (PQ.empty()) break;
			cur = PQ.top();
		}

		PQ.push(t[i][1]);
		res = max(res, (int)PQ.size());
	}

	cout << res;
}