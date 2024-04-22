#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>

using namespace std;
typedef pair<int, int> pii;

string str;
vector<pii> lr;
bool vis[200];
set<string> S;

void input() { 
	cin >> str; 
	
	stack<int> L;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') L.push(i);
		else if (str[i] == ')') {
			int l = L.top();
			L.pop();

			lr.push_back({ l, i });
		}
	}
}

void checkVis() {
	string res = "";

	for (int i = 0; i < str.size(); i++) {
		if (vis[i]) continue;
		res += str[i];
	}

	if (S.find(res) != S.end()) return;
	S.insert(res);
}

void recur(int index) {
	for (int i = index; i < lr.size(); i++) {
		int l = lr[i].first, r = lr[i].second;

		vis[l] = true;
		vis[r] = true;
		checkVis();

		recur(i + 1);

		vis[l] = false;
		vis[r] = false;
	}
}

void solve() {
	recur(0);

	for (string res : S) cout << res << "\n";
}

int main() { //°ýÈ£ Á¦°Å
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}