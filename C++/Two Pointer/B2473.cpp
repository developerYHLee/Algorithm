#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

int N;
ll arr[5001], m = 1e10;
int o1, o2, o3;

void b_search(int pivot, int r) {
	int l = pivot + 1;

	while (l < r) {
		ll k = arr[pivot] + arr[l] + arr[r];

		if (abs(k) < abs(m)) {
			o1 = pivot;
			o2 = l;
			o3 = r;
			m = k;
		}

		if (k < 0) l++;
		else if (k > 0) r--;
		else break;
	}
}

int main() { //¼¼ ¿ë¾×
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);

	for (int i = 0; i < N - 2; i++) b_search(i, N - 1);

	cout << arr[o1] << " " << arr[o2] << " " << arr[o3];
}