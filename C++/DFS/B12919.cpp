#include <iostream>
#include <algorithm>

using namespace std;

string S, T;
int sLen;
bool res;

void input() {
	cin >> S >> T; 
	sLen = S.size() - 1;
}

void recur(string s, string t) {
	if (!s.compare(t)) {
		res = true;
		return;
	}
	if (s.size() >= t.size()) return;

	if (t[0] == 'B') {
		string temp = t;
		temp.erase(temp.begin());
		reverse(temp.begin(), temp.end());
		recur(s, temp);
	}
	if (t[t.size() - 1] == 'A') {
		t.pop_back();
		recur(s, t);
	}
}

void solve() {
	recur(S, T);
	cout << res;
}

int main() { //A¿Í B 2
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}