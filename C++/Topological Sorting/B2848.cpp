#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int N, degree[26], alphaCnt;
bool vis[26], wrong;
vector<int> E[26];
string words[100]; 
queue<int> Q;

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> words[i];
	
		for (int j = 0; j < words[i].size(); j++) {
			int n = words[i][j] - 'a';

			if (!vis[n]) {
				vis[n] = true;
				alphaCnt++;
			}
		}
	}
}

void compareStr(const string& str1, const string& str2) {
	for (int i = 0; i < str1.size(); i++) {
		if (i == str2.size()) {
			wrong = true;
			return;
		}

		if (str1[i] == str2[i]) continue;

		int up = str1[i] - 'a', down = str2[i] - 'a';

		E[up].push_back(down);
		degree[down]++;

		return;
	}
}

void setDegree() {
	for (int i = 1; i < N; i++) compareStr(words[i - 1], words[i]);
}

bool pushQueue() {
	int cnt = 0;
	
	for (int i = 0; i < 26; i++) {
		if (vis[i] && !degree[i]) {
			Q.push(i);
			cnt++;
		}
	}

	return cnt >= 2 ? false : true;
}

bool pushQueue(int node) {
	int cnt = 0;

	for (int next : E[node]) {
		if (!--degree[next]) {
			Q.push(next);
			cnt++;
		}
	}

	return cnt >= 2 ? false : true;
}

string topologicalSort() {
	string ret = "";
	bool ch = false;

	if (!pushQueue()) ch = true;

	for (int i = 0; i < alphaCnt; i++) {
		if (!Q.size()) return "!";

		int node = Q.front();
		Q.pop();

		ret += 'a' + node;

		if (!pushQueue(node)) ch = true;
	}

	if (ch) return "?";
	else return ret;
}

void solve() {
	setDegree();

	if (wrong) cout << "!";
	else cout << topologicalSort();
}

int main() { ///¾Ë°í½ºÆÌ¾î
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}