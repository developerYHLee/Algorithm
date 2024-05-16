#include<iostream>

using namespace std;

int main() { //점수계산
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, res = 0, cnt = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		if (n) res += ++cnt;
		else cnt = 0;
	}

	cout << res;
}