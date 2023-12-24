#include <iostream>
#include <cmath>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

priority_queue<pii, vector<pii>, greater<pii>> PQ;
int N;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n1, n2;
		cin >> n1 >> n2;

		PQ.push({ n1, n2 });
	}
}

void solve() {
	priority_queue<int, vector<int>, greater<int>> temp;
	int cnt = 0;

	while (!PQ.empty()) {
		pii node = PQ.top();
		PQ.pop();

		int s = node.first, e = node.second;

		while (!temp.empty() && temp.top() <= s) { temp.pop(); }
		temp.push(e);

		cnt = max(cnt, (int)temp.size());
	}

	cout << cnt;
}

int main() { //강의실 배정
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}