#include <iostream>

using namespace std;

string str;
bool vis[5];

void input() { cin >> str; }

void recur(int index) {
	if (index == str.size()) return;

	string res = str.substr(0, index);
	char c = str[index];

	recur(index + 1);

	if (vis[c - '0'] || vis[4]) return;
	vis[c - '0'] = true;

	if (c == '4') {
		cout << res << "1\n"; 
		cout << res << "2\n";
		cout << res << "3\n";
	}
	else cout << res << "4\n";
}

void solve() {
	recur(1);
}

int main() { //Sierpinski »ï°¢Çü
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}