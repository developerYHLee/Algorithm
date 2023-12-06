#include <iostream>
#include <algorithm>

using namespace std;

int main() { //ทฮวม
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int* W = new int[N + 1];
	
	W[0] = 1e9;
	for (int i = 1; i <= N; i++) cin >> W[i];
	sort(W, W + N + 1, greater<int>());

	int res = 0;
	for (int i = 1; i <= N; i++) res = max(res, W[i] * i);
	cout << res;

	delete[] W;
}