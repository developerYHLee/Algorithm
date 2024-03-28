#include <iostream>

using namespace std;

string S;
int index;

void input() { cin >> S; }

int recur() {
	int ret = 0;
	
	while (index > 0) {
		index--;
		if (S[index] == ')') ret += recur() * (S[--index] - '0');
		else if (S[index] == '(') return ret;
		else ret++;
	}

	return ret;
}

void solve() {
	index = S.size();
	cout << recur();
}

int main() { //¾ÐÃà
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}