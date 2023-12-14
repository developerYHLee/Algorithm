#include <iostream>

using namespace std;

int main() { //핸드폰 요금
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int Y = 0, M = 0;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		Y += (num + 30) / 30 * 10;
		M += (num + 60) / 60 * 15;
	}

	if (Y == M) cout << "Y M " << Y;
	else if (Y > M) cout << "M " << M;
	else cout << "Y " << Y;
}