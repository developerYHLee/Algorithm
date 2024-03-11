#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int N;
bool G[2000];
vector<int> A;
map<int, int> M;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		if (M.find(n) == M.end()) {
			A.push_back(n);
			M.insert({ n, 1 });
		}
		else M[n]++;
	}
	sort(A.begin(), A.end());
}

void b_s(int s, int e, int key) {
	while (s < e) {
		int m = (s + e) / 2;

		if (A[m] == key) {
			G[m] = true;
			break;
		}
		else if (A[m] < key) s = m + 1;
		else e = m;
	}
}

void solve() {
	N = A.size();
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			b_s(0, i, A[i] + A[j]);
			b_s(i + 1, j, A[i] + A[j]);
			b_s(j + 1, N, A[i] + A[j]);
		}
	}

	for (int i = 0; i < N; i++) {
		if (!A[i]) {
			if (M[0] > 2) G[i] = true;
			continue;
		}
		if (M.find(0) != M.end() && M[A[i]] > 1) G[i] = true;
		else if (A[i] % 2 == 0) {
			int n = A[i] / 2;

			if (M.find(n) != M.end() && M[n] > 1) G[i] = true;
		}
	}

	int res = 0;
	for (int i = 0; i < N; i++) {
		if (G[i]) res += M[A[i]];
	}
	cout << res;
}

int main() { //ÁÁ´Ù
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}