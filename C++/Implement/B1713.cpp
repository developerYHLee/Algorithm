#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

vector<pii> recommend(101);

int main() { //후보 추천하기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int M;
	cin >> M;

	for (int i = 1; i <= 100; i++) recommend[i] = { 1e9, 1e9 };

	int c = 0;
	for (int i = 0; i < M; i++) {
		int s;
		cin >> s;

		if (recommend[s].first != 1e9) {
			recommend[s].first++;
			continue;
		}

		if (c == N) {
			int index = -1, MIN = 1e9 + 1, old = 1e9 + 1;
			for (int j = 1; j <= 100; j++) {
				if (MIN > recommend[j].first || (MIN == recommend[j].first && old > recommend[j].second)) {
					MIN = recommend[j].first;
					old = recommend[j].second;
					index = j;
				}
			}

			recommend[index].first = 1e9;
			recommend[index].second = 1e9;
			c--;
		}

		recommend[s].first = 1;
		recommend[s].second = i;
		c++;
	}

	for (int i = 1; i <= 100; i++) {
		if (recommend[i].first != 1e9) cout << i << " ";
	}
}