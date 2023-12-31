#include <iostream>
#include <cmath>
#include <queue>
#include <memory.h>

using namespace std;
typedef pair<int, int> pii;

pii pos[100];
int N, h_x, h_y ,tar_x, tar_y;
bool vis[100];

void input() {
	cin >> N;

	cin >> h_x >> h_y;
	for (int i = 0; i < N; i++) cin >> pos[i].first >> pos[i].second;
	cin >> tar_x >> tar_y;

	memset(vis, false, sizeof(vis));
}

int get_dis(int cur_x, int cur_y, int next_x, int next_y) {
	return abs(cur_x - next_x) + abs(cur_y - next_y);
}

bool solve() {
	queue<pii> Q;
	Q.push({ h_x, h_y });

	while (!Q.empty()) {
		pii cur = Q.front();
		Q.pop();

		int cur_x = cur.first, cur_y = cur.second;
		if (get_dis(cur_x, cur_y, tar_x, tar_y) <= 1000) return true;

		for (int i = 0; i < N; i++) {
			if (vis[i]) continue;

			int next_x = pos[i].first, next_y = pos[i].second;
			if (get_dis(cur_x, cur_y, next_x, next_y) <= 1000) {
				Q.push({ next_x, next_y });
				vis[i] = true;
			}
		}
	}

	return false;
}

int main() { //맥주 마시면서 걸어가기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T-- > 0) {
		input();
		cout << (solve() ? "happy" : "sad") << '\n';
	}
}