#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <memory.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const int MAX = 10001;

vi ans;
vvi scc, graph(MAX), scc_graph;
int id, sccnum[MAX], degree[MAX], sz[MAX];
bool finish[MAX], vis[MAX];
stack<int> S;

int make_scc(int n) {
	S.push(n);
	degree[n] = ++id;
	int ret = degree[n];

	for (int i : graph[n]) {
		if (!degree[i]) ret = min(ret, make_scc(i));
		else if (!finish[i]) ret = min(ret, degree[i]);
	}

	if (ret == degree[n]) {
		vi temp;

		while (true) {
			int cur = S.top();
			S.pop();

			sccnum[cur] = scc.size();
			degree[cur] = ret;
			finish[cur] = true;
			temp.push_back(cur);

			if (cur == n) break;
		}

		unique(temp.begin(), temp.end());
		scc.push_back(temp);
		sz[sccnum[n]] = scc[sccnum[n]].size();
	}

	return ret;
}

void make_scc_graph(int N) {
	scc_graph.resize(scc.size());

	for (int i = 1; i <= N; i++) {
		for (int j : graph[i]) {
			if (sccnum[i] == sccnum[j]) continue;
			scc_graph[sccnum[i]].push_back(sccnum[j]);
		}
	}
}

int dfs(int n) { //SCC DFS
	vis[n] = true;

	int ret = sz[n];
	for (int i : scc_graph[n]) {
		if (vis[i]) continue;
		ret += dfs(i);
	}

	return ret;
}

/*
int dfs(int n) { //일반적인 DFS
	vis[n] = true;

	int ret = 1;
	for (int i : graph[n]) {
		if (vis[i]) continue;
		ret += dfs(i);
	}

	return ret;
}
*/

void ans_scc_push(int n) {
	for (int i : scc[n]) ans.push_back(i);
}

int main() { //효율적인 해킹
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;

		graph[B].push_back(A);
	}

	for (int i = 1; i <= N; i++) {
		if (!finish[i]) make_scc(i);
	}
	make_scc_graph(N);

	int max_size = 0;

	for (int i = 0; i < scc.size(); i++) { //SCC DFS
		memset(vis, 0, sizeof(bool) * MAX);
		int s = dfs(i);

		if (max_size < s) {
			ans.clear();
			ans_scc_push(i);
			max_size = s;
		}
		else if (max_size == s) ans_scc_push(i);
	}

	/*
	for (int i = 1; i <= N; i++) { //일반적인 DFS
		memset(vis, 0, sizeof(bool) * MAX);
		int s = dfs(i);

		if (max_size < s) {
			ans.clear();
			ans.push_back(i);
			max_size = s;
		}
		else if (max_size == s) ans.push_back(i);
	}
	*/

	unique(ans.begin(), ans.end());
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}