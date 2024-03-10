#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, num[100];
vector<int> res;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> num[i];
	sort(num, num + N);
}

int getGCD(int a, int b) {
	while (b) {
		int temp = b;
		b = a % b;
		a = temp;
	}

	return a;
}

void solve() {
	int curGCD = num[1] - num[0];
	for (int i = 1; i < N - 1; i++) {
		curGCD = getGCD(curGCD, num[i + 1] - num[i]);
	}

	res.push_back(curGCD);
	for (int i = 2; i * i <= curGCD; i++) {
		if (curGCD % i == 0) {
			int n = curGCD / i;
			if (n != i) res.push_back(n);
			res.push_back(i);
		}
	}
	sort(res.begin(), res.end());

	for (int i : res) cout << i << " ";
}

int main() { //°Ë¹®
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}