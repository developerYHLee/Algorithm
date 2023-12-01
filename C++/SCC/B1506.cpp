#include <iostream>
#include <stack>
#include <cmath>
#include <vector>

using namespace std;

vector<vector<int>> graph;
int board[101][101], degree[101], cost[101], N, index = 1, res;
bool finish[101];
stack<int> S;

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> cost[i];
	for (int i = 1; i <= N; i++) {
		string str;
		cin >> str;

		for (int j = 1; j <= N; j++) board[i][j] = str[j - 1] - '0';
	}

	graph.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j]) graph[i].push_back(j);
		}
	}
}

int make_scc(int x) {
	S.push(x);
	degree[x] = index++;
	
	int ret = degree[x];
	for (int i : graph[x]) {
		if (!degree[i]) ret = min(ret, make_scc(i));
		else if(!finish[i]) ret = min(ret, degree[i]);
	}

	if (ret == degree[x]) {
		int m = 1e9;
		
		while (true) {
			int node = S.top();
			S.pop();

			m = min(m, cost[node]);
			finish[node] = true;

			if (node == x) {
				res += m;
				break;
			}
		}
	}

	return ret;
}

int main() { //°æÂû¼­
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	for (int i = 1; i <= N; i++) {
		if (!finish[i]) make_scc(i);
	}
	
	cout << res;
}