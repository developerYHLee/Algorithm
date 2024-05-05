#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, tri[3];
priority_queue<int> PQ;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		PQ.push(n);
	}
}

bool checkLine(int l1, int l2, int l3) {
	return l1 - (l2 + l3) >= 0 ? false : true;
}

bool checkTriangle() {
	if (!checkLine(tri[0], tri[1], tri[2])) return false;
	if (!checkLine(tri[1], tri[0], tri[2])) return false;
	if (!checkLine(tri[2], tri[0], tri[1])) return false;

	return true;
}

void solve() {
	tri[0] = PQ.top();
	PQ.pop();
	tri[1] = PQ.top();
	PQ.pop();
	tri[2] = PQ.top();
	PQ.pop();
	sort(tri, tri + 3);

	while (!PQ.empty() && !checkTriangle()) {
		tri[2] = PQ.top();
		PQ.pop();

		sort(tri, tri + 3);
	}

	if (checkTriangle()) cout << tri[0] + tri[1] + tri[2];
	else cout << -1;
}

int main() { //삼각형 만들기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}