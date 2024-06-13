#include <iostream>

using namespace std;

int N, M, arr[1400];

void input() {
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		int index = 0;

		int n1, n2, n3;
		cin >> n1 >> n2 >> n3;

		if (n2) {
			arr[n1]++;

			if (n3) arr[n1 + n2]++;
		}
		else if (n3) arr[n1] += 2;
	}
}

void solve() {
	int sz = N * 2 - 1;

	for (int i = 1; i < sz; i++) arr[i] += arr[i - 1];
	for (int i = 1; i <= N; i++) {
		cout << arr[N - i] + 1 << " ";
		for (int j = N; j < sz; j++) cout << arr[j] + 1 << " ";
		cout << "\n";
	}
}

int main() { //¿©¿Õ¹ú
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}