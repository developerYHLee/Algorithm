#include <iostream>

using namespace std;
typedef long long ll;

int sumT[302];
ll W[301];

void makeSumT() {
	for (int i = 1; i <= 301; i++) sumT[i] = sumT[i - 1] + i;
}

void makeW() {
	for (int i = 1; i <= 300; i++) W[i] = W[i - 1] + (ll)i * sumT[i + 1];
}

int main() { //»ï°¢¼öÀÇ ÇÕ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	makeSumT();
	makeW();

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		cout << W[N] << "\n";
	}
}