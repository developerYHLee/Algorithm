#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
typedef vector<int> vi;

int G;
vi res, divisor;

void GetDivisor() {
	int n = (int)sqrt(G);
	if (n * n == G) n--;

	for (int i = n; i > 0; i--) {
		if (G % i == 0) divisor.push_back(i);
	}
}

void input() {
	cin >> G;
	GetDivisor();
}

void solve() {
	for (int i = 0; i < divisor.size(); i++) {
		int n = divisor[i] + G / divisor[i];

		if (n % 2 == 0) res.push_back(n / 2);
	}

	if (res.size() == 0) cout << -1;
	else {
		for (int i : res) cout << i << "\n";
	}
}

int main() { //다이어트
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}