#include <iostream>
#include <cmath>

using namespace std;

int arr[300000];
int main() { //우리집엔 도서관이 있어
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) cin >> arr[i];

	int MAX = 0, res = 0;
	for (int i = 0; i < N; i++) {
		MAX = max(MAX, arr[i]);
		if (arr[i] < MAX) res = max(res, arr[i]);
	}

	cout << res;
}