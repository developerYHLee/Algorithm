#include <iostream>
#include <stack>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;

int H, W;

void input() {
	cin >> H >> W;
}

void solve() {
	int res = 0, maxH = 0;
	stack<pii> S;

	for (int i = 0; i < W; i++) {
		int h, w = i;
		cin >> h;

		int tempH = min(maxH, h);

		while (!S.empty()) {
			pii node = S.top();

			int height = node.first, x = node.second;
		
			if (h < height) break;
			S.pop();

			res += (w - x) * (tempH - height);
			w = x;
		}

		S.push({ h, w });
		maxH = max(maxH, h);
	}

	cout << res;
}

int main() { //ºø¹°
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}