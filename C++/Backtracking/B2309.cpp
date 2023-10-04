#include <iostream>
#include <algorithm>

using namespace std;

int check[7], h[9];
bool solve(int sum, int index, int x) {
	if (index == 7) return sum == 100;

	for (int i = x; i < 9; i++) {
		check[index] = h[i];
		if (solve(sum + h[i], index + 1, i + 1)) return true;;
	}

	return false;
}

int main() { //ÀÏ°ö ³­ÀïÀÌ
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; i++) cin >> h[i];
	solve(0, 0, 0);
	sort(check, check + 7);

	for (int i = 0; i < 7; i++) cout << check[i] << "\n";
}