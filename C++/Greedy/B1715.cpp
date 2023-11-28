#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

int main() { //카드 정렬하기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> PQ;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		PQ.push(num);
	}

	ll res = 0;
	while (true) {
		if (PQ.size() == 1) break;

		int card = PQ.top();
		PQ.pop();

		card += PQ.top();
		PQ.pop();

		PQ.push(card);
		res += card;
	}

	cout << res;
}