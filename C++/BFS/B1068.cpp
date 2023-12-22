#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, arr[50], E;
vector<int> tree[50];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cin >> E;
}

int solve() {
	int ret = 0;

	queue<int> Q;
	for (int i = 0; i < N; i++) {
		if (i == E) continue;
		if (arr[i] == -1) Q.push(i);
		else tree[arr[i]].push_back(i);
	}

	while (!Q.empty()) {
		int node = Q.front();
		Q.pop();

		if (!tree[node].size()) ret++;
		for (int n : tree[node]) Q.push(n);
	}

	return ret;
}

int main() { //Æ®¸®
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	cout << solve();
}