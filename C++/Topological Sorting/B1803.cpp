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

		//Ȱ�� ������ �ܳ��Ѵ�.
		res[me][team] = true;

		//degree�� -1�� ��� ���� Ȱ�̵� ���е� Ȯ�� ���� ���̴�.
		degree[me][team] = -1;

		if (degree[my_target][!team] <= -1) continue;
		degree[my_target][!team] = -1;

		//���и� �� ����� Ȱ�� �� �� ���� ������ ǥ���� degree�� �ϳ� ���ش�.
		int delete_target = target[my_target][!team];
		if (--degree[delete_target][team] == 0) Q.push({ delete_target, team });
	}
}

int main() { //���� ����
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