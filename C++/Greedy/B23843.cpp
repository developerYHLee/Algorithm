#include <iostream>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int t[10000];

int main() { //ÄÜ¼¾Æ®
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) cin >> t[i];
	sort(t, t + N, greater());

	int res = 0;
	stack<pii> S;
	for (int i = 0; i < N; i++) {
		if (S.size() == 0) res += t[i];
		if (S.size() < M) S.push({ t[i], t[i] });
		else {
			pii prev = S.top();
			S.pop();

			int remove_t = prev.first;
			while (!S.empty()) {
				pii cur = S.top();
				S.pop();

				int remain_t = cur.second;
				if (remain_t <= remove_t) remove_t = cur.first;
				else {
					S.push({ cur.first, remain_t - remove_t });
					break;
				}
			}
			i--;
		}
	}

	cout << res;
}