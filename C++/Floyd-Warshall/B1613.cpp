#include <iostream>
#include <algorithm>

using namespace std;

int map[401][401];

int main() { //¿ª»ç
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) fill_n(map[i], N + 1, 1e9);
	for (int i = 0; i < M; i++) {
		int n1, n2;
		cin >> n1 >> n2;

		map[n1][n2] = 1;
	}

	for (int v = 1; v <= N; v++) {
		for (int s = 1; s <= N; s++) {
			if (v == s) continue;

			for (int e = 1; e <= N; e++) {
				if (v == e || s == e) continue;

				map[s][e] = min(map[s][e], map[s][v] + map[v][e]);
			}
		}
	}

	int S;
	cin >> S;

	for (int i = 0; i < S; i++) {
		int n1, n2;
		cin >> n1 >> n2;

		if (map[n1][n2] == 1e9) {
			if (map[n2][n1] != 1e9) cout << "1\n";
			else cout << "0\n";
		}
		else cout << "-1\n";
	}
}