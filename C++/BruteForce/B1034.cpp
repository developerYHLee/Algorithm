#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N, M, K, res;
string lamp[50];
vector<int> temp;

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> lamp[i];
	cin >> K;
}

void setRes() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		cnt++;
		for (int j = 0; j < M; j++) {
			if (lamp[i][j] == '0') {
				cnt--;
				break;
			}
		}
	}
	res = max(res, cnt);
}

void changeLamp(int index) {
	for (int i = 0; i < N; i++) lamp[i][index] = lamp[i][index] == '1' ? '0' : '1';
}

void solve() {
	for (int i = 0; i < N; i++) {
		temp.clear();

		for (int j = 0; j < M; j++) {
			if (lamp[i][j] == '0') {
				temp.push_back(j);
				changeLamp(j);
			}
		}

		if(K >= temp.size() && (K - temp.size()) % 2 == 0) setRes();

		for (int j : temp) changeLamp(j);
	}

	cout << res;
}

int main() { //ทฅวม
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}