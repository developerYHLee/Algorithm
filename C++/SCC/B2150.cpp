#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
typedef vector<vector<int>> vvi;

vvi scc, graph(10001);
int degree[10001], sccnum[10001], id;
bool finish[10001];
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
		while (true) {
			int cur = S.top();
			S.pop();

			degree[cur] = ret;
			finish[cur] = true;

			if (cur == n) break;
		}
	}

	return ret;
}

void print_scc(int n) {
	for (int i = 0; i < scc[n].size(); i++) cout << scc[n][i] << " ";
	cout << "-1\n";
}

int main() { //Strongly Connected Component
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int V, E;
	cin >> V >> E;

	for (int i = 0; i < E; i++) {
		int A, B;
		cin >> A >> B;

		graph[A].push_back(B);
	}

	for (int i = 1; i <= V; i++) {
		if (!finish[i]) make_scc(i);
	}

	for (int i = 1; i <= V; i++) {
		if (!sccnum[degree[i]]) {
			int index = scc.size() + 1;
			
			scc.push_back({ i });
			sccnum[degree[i]] = index;
		}
		else scc[sccnum[degree[i]] - 1].push_back(i);
	}

	cout << scc.size() << '\n';
	for(int i = 0; i < scc.size(); i++) print_scc(i);
}