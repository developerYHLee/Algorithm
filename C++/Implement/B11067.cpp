#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> X[100001];
int T, N, M, maxX, cafe[10];
priority_queue<int, vector<int>, greater<int>> sortedCafe;
unordered_map<int, string> res;

void printRes() {
	for (int i = 0; i < M; i++) cout << res[cafe[i]] << "\n";
}

void checkAns(int x, int y, int cnt, int& m) {
	int n = sortedCafe.top();

	if (cnt == n) {
		while (!sortedCafe.empty()) {
			if (sortedCafe.top() != n) break;

			sortedCafe.pop();
		}

		if (res.find(n) == res.end()) res.insert({ n, to_string(x) + " " + to_string(y) });
		m++;
	}
}

void solve() {
	int m = 0, cnt = 0, y = 0;

	for (int x = 0; x <= maxX; x++) {
		if (!X[x].size()) continue;

		int sz = X[x].size();

		if (y == X[x][0]) {
			for (int i = 0; i < sz; i++) {
				y = X[x][i];
				checkAns(x, y, ++cnt, m);
			}
		}
		else {
			for (int i = sz - 1; i >= 0; i--) {
				y = X[x][i];
				checkAns(x, y, ++cnt, m);
			}
		}
	}
}

void input() {
	cin >> T;
	
	while (T-- > 0) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y;

			X[x].push_back(y);

			maxX = max(maxX, x);
		}

		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> cafe[i]; 
			sortedCafe.push(cafe[i]);
		}

		for (int i = 0; i <= maxX; i++) sort(X[i].begin(), X[i].end());

		solve();
		printRes();

		for (int i = 0; i <= maxX; i++) X[i].clear();
		res.clear();
	}
}

int main() { //¸ð³ëÅæ±æ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
}