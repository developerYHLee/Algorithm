#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main() { //Àü·Â³­
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	while (true) {
		ll cost = 0;

		priority_queue<pii, vector<pii>, greater<pii>> PQ;
		vector<vector<pii>> map(N);
		vector<bool> vis(N, false);
		for (int i = 0; i < M; i++) {
			int s, e, d;

			cin >> s >> e >> d;

			cost += d;
			map[s].push_back({ d, e });
			map[e].push_back({ d, s });
		}

		int sum = 0;
		PQ.push({ 0, 0 });
		while (!PQ.empty()) {
			pii cur = PQ.top();
			PQ.pop();

			int node = cur.second, dis = cur.first;
			if (vis[node]) continue;
			vis[node] = true;
			sum += dis;

			for (pii next : map[node]) {
				int n = next.second, d = next.first;

				if (vis[n]) continue;
				PQ.push({ d, n });
			}
		}

		cin >> N >> M;

		cout << cost - sum << endl;
		if (N == 0 && M == 0) break;
	}
}