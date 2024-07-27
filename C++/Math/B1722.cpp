#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

int N;
bool vis[21];

ll getF(int k) { 
	if (k <= 1) return 1;
	return k * getF(k - 1); 
}

int getNum(int cnt) {
	for (int i = 1; i <= N; i++) {
		if (!vis[i]) {
			if(--cnt == 0) return i;
		}
	}

	return -1;
}

int getCnt(int num) {
	int ret = 0;

	for (int i = 1; i <= N; i++) {
		if (!vis[i]) {
			ret++;
			if (num == i) return ret;
		}
	}

	return -1;
}

void solve1() {
	ll k;
	cin >> k;

	string res = "";
	int tempN = N;

	while (k > 1) {
		int cnt = 1;
		ll temp = getF(--tempN);

		while (temp * cnt < k) cnt++;

		int num = getNum(cnt);
		vis[num] = true;

		res += to_string(num) + " ";

		k -= temp * (cnt - 1);
	}

	while (tempN--) {
		int num = getNum(1);
		vis[num] = true;
		res += to_string(num) + " ";
	}

	cout << res;
}

void solve2() {
	ll res = 0;

	for (int i = N - 1; i >= 0; i--) {
		int k;
		cin >> k;

		int cnt = getCnt(k);
		vis[k] = true;

		res += getF(i) * (cnt - 1);
	}

	cout << res + 1;
}

void input() {
	int K;

	cin >> N >> K;
	if (K == 1) solve1();
	else solve2();
}

int main() { //순열의 순서
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
}