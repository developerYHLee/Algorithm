#include <iostream>
#include <stack>
#include <cmath>
#include <vector>
#include <memory.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi graph;
bool finish[100001];
int id, N, M, degree[100001], degree_scc[100001], scc_num[100001], scc_sz;
stack<int> S;

void reset() {
	id = 1;
	scc_sz = 0;

	memset(finish, false, (N + 1) * sizeof(bool));
	memset(degree, 0, (N + 1) * sizeof(int));
	memset(degree_scc, 0, (N + 1) * sizeof(int));
	memset(scc_num, 0, (N + 1) * sizeof(int));
	graph.clear();
	graph.resize(N + 1);
}

void input() {
	cin >> N >> M;

	reset();
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
	}
}

int make_scc(int x) {
	S.push(x);

	int ret = id++;
	degree[x] = ret;

	for (int i : graph[x]) {
		if (!degree[i]) ret = min(ret, make_scc(i));
		else if (!finish[i]) ret = min(ret, degree[i]);
	}

	if (ret == degree[x]) {
		while (true) {
			int cur = S.top();
			S.pop();

			finish[cur] = true;
			degree[cur] = ret;
			scc_num[cur] = scc_sz;
			if (cur == x) break;
		}
		scc_sz++;
	}

	return ret;
}

void scc() {
	for (int i = 1; i <= N; i++) {
		for (int j : graph[i]) {
			if (scc_num[i] == scc_num[j]) continue;
			degree_scc[scc_num[j]]++;
		}
	}
}

int solve() {
	int ret = 0;

	for (int i = 0; i < scc_sz; i++) {
		if (!degree_scc[i]) ret++;
	}

	return ret;
}

int main() { //µµ¹Ì³ë
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;

	while (T-- > 0) {
		input();
		for (int i = 1; i <= N; i++) {
			if (!finish[i]) make_scc(i);
		}
		scc();
		cout << solve() << '\n';
	}
}