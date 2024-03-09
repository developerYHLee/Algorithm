#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

string sortName[1000];
vector<int> arr[1000];
map<string, int> dic;
int degree[1000], N, M;
vector<int> ch[1000];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> sortName[i];
	sort(sortName, sortName + N);
	for (int i = 0; i < N; i++) dic.insert({ sortName[i], i });

	cin >> M;
	cin.ignore();
	for (int i = 0; i < M; i++) {
		string str, n1, n2;
		getline(cin, str);

		stringstream ss(str);
		ss >> n1 >> n2;

		degree[dic[n1]]++;
		arr[dic[n2]].push_back(dic[n1]);
	}
}

void solve() {
	int cnt = 0;
	string p = "";
	queue<int> Q;
	for (int i = 0; i < N; i++) {
		if (!degree[i]) {
			Q.push(i);
			p += sortName[i] + " ";
			cnt++;
		}
	}

	while (!Q.empty()) {
		int node = Q.front();
		Q.pop();

		for (int i : arr[node]) {
			if (--degree[i] == 0) {
				ch[node].push_back(i);
				Q.push(i);
			}
		}
	}

	cout << cnt << "\n" << p << "\n";
	for (int i = 0; i < N; i++) {
		cout << sortName[i] << " " << ch[i].size();
		sort(ch[i].begin(), ch[i].end());
		for (int j : ch[i]) cout << " " << sortName[j];
		cout << "\n";
	}
}

int main() { //계보 복원가 호석
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}