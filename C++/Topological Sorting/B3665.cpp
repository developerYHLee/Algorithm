#include <iostream>
#include <queue>
#include<memory.h>

using namespace std;

int res[500], degree[501];
bool map[501][501];

int topological_sorting(int N) {
	queue<int> Q;
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) Q.push(i);
	}

	for (int i = 0; i < N; i++) {
		if (Q.empty()) return -1;
		if (Q.size() > 1) return 0;

		int prev = Q.front();
		Q.pop();

		res[i] = prev;
		
		for (int j = 1; j <= N; j++) {
			if (!map[prev][j]) continue;
			if (--degree[j] == 0) Q.push(j);
		}
	}

	return 1;
}

void make_map(const vector<int>& record, const vector<pair<int, int>>& change) {
	for (int i = 0; i < record.size(); i++) {
		int n1 = record[i];
		for (int j = i + 1; j < record.size(); j++) {
			int n2 = record[j];
			map[n1][n2] = true;
			degree[n2]++;
		}
	}

	for (int i = 0; i < change.size(); i++) {
		int n1 = change[i].first, n2 = change[i].second;

		if (map[n1][n2]) {
			map[n1][n2] = false;
			map[n2][n1] = true;
			degree[n1]++;
			degree[n2]--;
		}
		else if (map[n2][n1]) {
			map[n2][n1] = false;
			map[n1][n2] = true;
			degree[n2]++;
			degree[n1]--;
		}
	}
}

int main() { //최종 순위
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T-- > 0) {
		int N;
		cin >> N;

		memset(res, 0, 500 * sizeof(int));
		memset(degree, 0, 501 * sizeof(int));
		for (int i = 0; i <= 500; i++) memset(map[i], 0, 501 * sizeof(bool));

		vector<int> record(N);
		for (int i = 0; i < N; i++) cin >> record[i];
		
		int M;
		cin >> M;

		vector<pair<int, int>> change(M);
		for (int i = 0; i < M; i++) {
			int n1, n2;
			cin >> n1 >> n2;

			change[i].first = n1;
			change[i].second = n2;
		}
		
		make_map(record, change);
		int check = topological_sorting(N);
		if (check == -1) cout << "IMPOSSIBLE" << endl;
		else if (check == 0) cout << "?" << endl;
		else {
			for (int i = 0; i < N; i++) cout << res[i] << " ";
			cout << endl;
		}
	}
}