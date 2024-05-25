#include <iostream>
#include <string>

using namespace std;

string str;
int index;

void check(string n) {
	for (char c : n) {
		if (c == str[index]) {
			index++;

			if (index == str.length()) return;
		}
	}
}

void solve() {
	int i = 1;
	while (true) {
		check(to_string(i));

		if (index == str.length()) break;
		i++;
	}
	cout << i;
}

int main() { //수 이어 쓰기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> str;
	solve();
}