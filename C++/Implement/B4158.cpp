#include <iostream>
#include <unordered_set>

using namespace std;

int N, M, res;
unordered_set<int> S;

bool input() {
	res = 0;
	cin >> N >> M;
	
	if (N == 0 && M == 0) return false;
	S.clear();
	
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		S.insert(n);
	}

	for (int j = 0; j < M; j++) {
		int m;
		cin >> m;

		if (S.find(m) != S.end()) res++;
	}

	return true;
}

int main() { //CD
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	while(input()) cout << res << "\n";
}