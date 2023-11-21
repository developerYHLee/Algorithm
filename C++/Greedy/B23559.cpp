#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int cost[100000][2];
priority_queue<pii> PQ;

int main() { //นไ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, X;
	cin >> N >> X;

	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;

		cost[i][0] = A;
		cost[i][1] = B;

		int sub = A - B;
		PQ.push({ sub, i });
	}

	int res = 0;
	while (!PQ.empty()) {
		pii cur = PQ.top();
		PQ.pop();

		int price = cur.first, i = cur.second;

		if (price <= 0 || (N - 1) * 1000 > X - 5000) {
			X -= 1000;
			res += cost[i][1];
		}
		else {
			X -= 5000;
			res += cost[i][0];
		}

		N--;
	}

	cout << res;
}