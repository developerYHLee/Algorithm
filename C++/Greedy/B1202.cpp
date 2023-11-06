#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

vector<pii> jewel;
vector<int> C;
priority_queue<int> PQ;

int main() { //º¸¼® µµµÏ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;
	
	jewel.resize(N);
	for (int i = 0; i < N; i++) {
		int m, v;
		cin >> m >> v;

		jewel[i].first = m;
		jewel[i].second = v;
	}

	C.resize(K);
	for (int i = 0; i < K; i++) cin >> C[i];

	sort(jewel.begin(), jewel.end());
	sort(C.begin(), C.end());

	ll res = 0;
	for (int i = 0, index = 0; i < K; i++) {
		int c = C[i];

		while (index < N) {
			int m = jewel[index].first, v = jewel[index].second;
			
			if (c < m) break;

			PQ.push(v);
			index++;
		}

		if (!PQ.empty()) {
			res += PQ.top();
			PQ.pop();
		}
	}

	cout << res;
}