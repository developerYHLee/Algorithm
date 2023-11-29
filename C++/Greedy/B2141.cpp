#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

pii village[100000];
int main() { //¿ìÃ¼±¹
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	ll sum = 0;
	for (int i = 0; i < N; i++) {
		int X, A;
		cin >> X >> A;
		sum += A;

		village[i].first = X;
		village[i].second = A;
	}
	sort(village, village + N);

	ll temp = 0;
	for (int i = 0; i < N; i++) {
		temp += village[i].second;

		if (temp >= (sum + 1) / 2) {
			cout << village[i].first;
			break;
		}
	}
}