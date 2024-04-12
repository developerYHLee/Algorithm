#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int N, M;
string str[1000];

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;

		for (int j = 0; j < M; j++) str[j] += temp[j];
	}

	for (int i = 0; i < M; i++) reverse(str[i].begin(), str[i].end());
}

void solve() {
	int cnt = 0;

	while (true) {
		if (cnt == M) {
			cout << cnt;
			return;
		}

		set<string> S;
		for (int i = 0; i < M; i++) {
			str[i].pop_back();
			if (S.find(str[i]) == S.end()) S.insert(str[i]);
			else {
				cout << cnt;
				return;
			}
		}

		cnt++;
	}
}

int main() { //문자열 잘라내기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}