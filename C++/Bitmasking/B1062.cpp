#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

int N, K, res;
vector<int> word[50];
ll key;
bool vis[26];

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		for (char c : str) word[i].push_back(c - 'a');
	}

	key += 1;
	vis[0] = true;
	key += ((ll)1 << 2);
	vis[2] = true;
	key += ((ll)1 << 8);
	vis[8] = true;
	key += ((ll)1 << 13);
	vis[13] = true;
	key += ((ll)1 << 19);
	vis[19] = true;
	K -= 5;
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
		if (vis[i]) continue;

		key += ((ll)1 << i);
		recur(i + 1, cnt + 1);
		key -= ((ll)1 << i);
	}
}

void solve() {
	recur(0, 0);
	cout << res;
}

int main() { //°¡¸£Ä§
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}