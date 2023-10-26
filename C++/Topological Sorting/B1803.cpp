#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, bool> pib;

int degree[50001][2], target[50001][2];
bool res[2][50001];
int N, M, c;

void topological_sort() {
	queue<pib> Q;
	for (int i = 1; i <= N; i++) {
		if (degree[i][0] == 0) {
			Q.push({ i, false });
			degree[i][0] = -1;
		}
	}
	for (int i = 1; i <= M; i++) {
		if (degree[i][1] == 0) {
			Q.push({ i, true });
			degree[i][1] = -1;
		}
	}

	while (!Q.empty()) {
		pib cur = Q.front();
		Q.pop();
		c++;

		bool team = cur.second, enemy = !team;
		int index = cur.first, cur_target = target[index][team];

		res[enemy][cur_target] = false;
		degree[cur_target][enemy] = -1;

		//방패를 든 사람은 활을 쏠 수 없기 때문에 표적의 degree를 하나 빼준다.
		int delete_target = target[cur_target][enemy];
		if (--degree[delete_target][team] == 0) {
			Q.push({ delete_target, team });
			degree[delete_target][team] = -1;
		}
	}
}

int main() { //무술 연습
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> target[i][0];
		degree[target[i][0]][1]++;
	}
	for (int i = 1; i <= M; i++) {
		cin >> target[i][1];
		degree[target[i][1]][0]++;
	}
	fill_n(res[0], N + 1, true);
	fill_n(res[1], M + 1, true);

	int w = N + M;
	w = w % 2 == 0 ? w : w + 1;

	topological_sort();
	while (c < w / 2) {
		for (int i = 1; i <= N; i++) {
			if (res[0][i] && degree[i][0] != -1) {
				int t = target[i][0];
				
				if (res[1][t] && degree[t][1] != -1) {
					res[1][t] = false;
					degree[t][1] = -1;
					degree[i][0] = 0;

					break;
				}
			}
		}

		topological_sort();
	}

	for (int i = 1; i <= N; i++) cout << res[0][i];
	cout << '\n';
	for (int i = 1; i <= M; i++) cout << res[1][i];
}