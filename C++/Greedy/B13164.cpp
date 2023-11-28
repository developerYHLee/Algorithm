#include <iostream>
#include <algorithm>

using namespace std;
const int MAX_N = 300000;

int h[MAX_N], m[MAX_N - 1];
int main() { //행복 유치원
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> h[i];
	for (int i = 1; i < N; i++) m[i - 1] = h[i] - h[i - 1];
	sort(m, m + N - 1);

	int res = 0;
	for (int i = 0; i < N - K; i++) res += m[i];
	cout << res;
}