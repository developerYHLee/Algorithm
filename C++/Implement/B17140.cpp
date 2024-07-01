#include <iostream>
#include <cmath>
#include <memory.h>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
	int num, cnt;

	Node(int num, int cnt) : num(num), cnt(cnt) {}

	bool operator<(const Node &l) const {
		if (cnt == l.cnt) return num < l.num;
		return cnt < l.cnt;
	}
};

int R, C, K, cnt[101], arr[101][101], temp[101][101], maxRow, maxCol;

void input() {
	cin >> R >> C >> K;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) cin >> arr[i][j];
	}
	maxRow = 3;
	maxCol = 3;
}

void rowOperator() {
	maxCol = 0;

	for (int i = 1; i <= maxRow; i++) {
		memset(cnt, 0, sizeof(cnt));

		for (int j = 1; j <= 100; j++) {
			if (!temp[i][j]) continue;

			cnt[temp[i][j]]++;
		}

		vector<Node> storage;
		for (int j = 1; j <= 100; j++) {
			if (!cnt[j]) continue;

			storage.push_back(Node(j, cnt[j]));
		}
		sort(storage.begin(), storage.end());

		int index = 1;
		for (Node node : storage) {
			if (index > 100) break;

			int n = node.num, c = node.cnt;
			arr[i][index++] = n;
			arr[i][index++] = c;
		}
		for (int j = index; j <= 100; j++) arr[i][j] = 0;

		maxCol = max(maxCol, index - 1);
	}
}

void colOperator() {
	maxRow = 0;

	for (int j = 1; j <= maxCol; j++) { 
		memset(cnt, 0, sizeof(cnt));

		for (int i = 1; i <= 100; i++) {
			if (!temp[i][j]) continue;

			cnt[temp[i][j]]++;
		}

		vector<Node> storage;
		for (int i = 1; i <= 100; i++) {
			if (!cnt[i]) continue;

			storage.push_back(Node(i, cnt[i]));
		}
		sort(storage.begin(), storage.end());

		int index = 1;
		for (Node node : storage) {
			if (index > 100) break;

			int n = node.num, c = node.cnt;
			arr[index++][j] = n;
			arr[index++][j] = c;
		}
		for (int i = index; i <= 100; i++) arr[i][j] = 0;

		maxRow = max(maxRow, index - 1);
	}
}

void arrayOperator() {
	if (maxRow >= maxCol) rowOperator();
	else colOperator();
}

void solve() {
	int res = 0;
	
	while (arr[R][C] != K) {
		if (res >= 100) {
			res = -1;
			break;
		}

		res++;
		memcpy(temp, arr, sizeof(arr));
		arrayOperator();
	}

	cout << res;
}

int main() { //이차원 배열과 연산
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}