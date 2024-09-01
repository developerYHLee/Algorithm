#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

ll res;
int N, num[10000];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> num[i];
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) res += abs(num[i] - num[j]);
	}

	cout << res * 2;
}

int main() { //거리의 합
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	input();
	solve();
}