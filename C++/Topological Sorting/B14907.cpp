#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

struct Node {
	int process, time;

	Node(int p, int t) : process(p), time(t) {}
};

int degree[26], cost[26], dp[26], res;
vector<int> E[26];

void input() {
	string str;
	
	while (getline(cin, str)) {
		stringstream ss(str);

		string process, time, other;
		ss >> process >> time >> other;

		int p = process[0] - 'A', t = stoi(time), o;
		
		cost[p] = t;

		for (int i = 0; i < other.size(); i++) {
			o = other[i] - 'A';
			E[o].push_back(p);
			degree[p]++;
		}
	}
}

void solve() {
	queue<Node> Q;

	for (int i = 0; i < 26; i++) {
		if (!degree[i]) Q.push(Node(i, cost[i]));
	}

	while (!Q.empty()) {
		Node node = Q.front();
		Q.pop();

		int process = node.process, time = node.time;

		res = max(res, time);

		for (int next : E[process]) {
			dp[next] = max(dp[next], time + cost[next]);
			if (--degree[next] == 0) Q.push(Node(next, dp[next]));
		}
	}

	cout << res;
}

int main() { //프로젝트 스케줄링
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}