#include <iostream>
#include <cmath>
#include <memory.h>

using namespace std;

bool res[1000000];
void solve(int N, int index) {
	if (!N) {
		res[index] = true;
		return;
	}

	solve(N - 1, index);
	solve(N - 1, index + pow(3, N - 1) * 2);
}

void print_res(int N) {
	int sz = pow(3, N);
	for (int i = 0; i < sz; i++) {
		if (res[i]) cout << "-";
		else cout << " ";
	}
	cout << "\n";
}

int main() { //Ä­Åä¾î ÁýÇÕ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve(12, 0);

	int N;
	while (cin >> N) print_res(N);
}