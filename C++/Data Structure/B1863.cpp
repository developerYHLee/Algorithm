#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
typedef pair<int, int> pii;

int N;
pii pos[50'000];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> pos[i].first >> pos[i].second;
	sort(pos, pos + N);
}

void solve() {
	int res = 0;
	stack<int> S;

	for (int i = 0; i < N; i++) {
		int y = pos[i].second;

		while (!S.empty()) {
			int prevY = S.top();

			if (prevY > y) {
				res++;
				S.pop();
			}
			else {
				if (prevY == y) S.pop();
				break;
			}
		}

		if(y) S.push(y);
	}

	cout << res + S.size();
}

int main() { //스카이라인 쉬운거
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}