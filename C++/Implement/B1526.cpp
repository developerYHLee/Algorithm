#include <iostream>
#include <queue>

using namespace std;

int main() { //가장 큰 금민수
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int str;
	cin >> str;

	queue<int> Q;
	Q.push(0);

	int res = 0;
	while (!Q.empty()) {
		int node = Q.front();
		Q.pop();

		if (node > str) break;
		res = node;

		Q.push(node * 10 + 4);
		Q.push(node * 10 + 7);
	}

	cout << res;
}