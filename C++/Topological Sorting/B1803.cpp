#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, bool> pib;

int degree[50001][2], target[50001][2];
bool res[50001][2];
int N, M;

int make_target(int me, bool team) {
	return target[me][team];
}

void topological_sort() {
	queue<pib> Q;

	for (int i = 1; i <= N; i++) {
		if (degree[i][0] == 0) Q.push({ i, 0 });
	}
	for (int i = 1; i <= M; i++) {
		if (degree[i][1] == 0) Q.push({ i, 1 });
	}

	while (!Q.empty()) {
		pib cur = Q.front();
		Q.pop();

		bool team = cur.second;
		int me = cur.first, my_target = make_target(me, team);

		//활을 적에게 겨냥한다.
		res[me][team] = true;

		//degree가 -1이 라는 것은 활이든 방패든 확정 짓는 것이다.
		degree[me][team] = -1;

		if (degree[my_target][!team] <= -1) continue;
		degree[my_target][!team] = -1;

		//방패를 든 사람은 활을 쏠 수 없기 때문에 표적의 degree를 하나 빼준다.
		int delete_target = target[my_target][!team];
		if (--degree[delete_target][team] == 0) Q.push({ delete_target, team });
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
	topological_sort();
	
	for (int i = 1; i <= N; i++) {
		if (degree[i][0] > 0) res[i][0] = true;
	}

	for (int i = 1; i <= N; i++) cout << res[i][0];
	cout << "\n";
	for (int i = 1; i <= M; i++) cout << res[i][1];
}