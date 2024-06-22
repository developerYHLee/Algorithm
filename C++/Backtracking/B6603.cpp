#include <iostream>
#include <string>

using namespace std;

int N, arr[13];

void input() {
	for (int i = 0; i < N; i++) cin >> arr[i];
}

void recur(int index, int k, string str) {
	if (k == 6) {
		cout << str << "\n";
		return;
	}

	for (int i = index; i < N; i++) recur(i + 1, k + 1, str + to_string(arr[i]) + " ");
}

void solve() {
	recur(0, 0, "");
	cout << "\n";
}

int main() { //·Î¶Ç
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	while (N) {
		input();
		solve();
		cin >> N;
	}
}