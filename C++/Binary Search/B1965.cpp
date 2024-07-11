#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, box[1000];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> box[i];
}

void solve() {
	vector<int> temp;

	for (int i = 0; i < N; i++) {
		auto iter = lower_bound(temp.begin(), temp.end(), box[i]);

		if (iter == temp.end()) temp.push_back(box[i]);
		else temp[iter - temp.begin()] = box[i];
	}

	cout << temp.size();
}

int main() { //상자넣기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}