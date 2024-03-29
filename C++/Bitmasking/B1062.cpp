#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int N, K, res;
vector<int> word[50];
ll key;

void setAntic(char a) {
	int n = a - 'a';

	key |= ((ll)1 << n);
	K--;
}

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (char c : str) word[i].push_back(c - 'a');
	}

	setAntic('a');
	setAntic('n');
	setAntic('t');
	setAntic('i');
	setAntic('c');
}

void checkAlpha() {
	int temp = 0;

	for (int i = 0; i < N; i++) {
		bool ch = true;

		for (int n : word[i]) {
			if (!(((ll)1 << n) & key)) {
				ch = false;
				break;
			}
		}

		if (ch) temp++;
	}

	res = max(res, temp);
}

void recur(int index, int cnt) {
	if (cnt == K) {
		checkAlpha();
		return;
	}

	for (int i = index; i < 26; i++) {
		if (key & ((ll)1 << i)) continue;

		key |= ((ll)1 << i);
		recur(i + 1, cnt + 1);
		key &= ~((ll)1 << i);
	}
}

void solve() {
	recur(0, 0);
	cout << res;
}

int main() { //����ħ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}