#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

ll num[10], res = -1e12;
int N, sz;
char op[10];

ll cal(ll n1, ll n2, int index) {
	switch (op[index]) {
	case '+':
		return n1 + n2;
	case '-':
		return n1 - n2;
	case '*':
		return n1 * n2;
	}

	return -1;
}

void recur(int i, ll sum, ll n, bool o) {
	if (i == sz) {
		if (!o) sum = cal(sum, num[sz], i - 1);
		else sum = cal(sum, cal(n, num[sz], i - 1), i - 2);

		res = max(res, sum);

		return;
	}
	if (!o) {
		recur(i + 1, cal(sum, num[i], i - 1), 0, false);
		recur(i + 1, sum, num[i], true);
	}
	else recur(i + 1, cal(sum, cal(n, num[i], i - 1), i - 2), 0, false);
}

void input() {
	cin >> N;
	string str;
	cin >> str;

	int n_i = 0, c_i = 0;
	for (int i = 0; i < N;) {
		num[n_i++] = str[i++] - '0';
		op[c_i++] = str[i++];
	}

	sz = N / 2;
}

int main() { //괄호 추가하기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	if (N > 1) recur(1, num[0], 0, false);
	else res = num[0];
	cout << res;
}