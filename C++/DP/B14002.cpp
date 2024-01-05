#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, arr[1001], p[1001];
vector<int> temp;

void solve() {
	for (int i = 1; i <= N; i++) {
		int index = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
		
		if (index == temp.size()) {
			temp.push_back(arr[i]);
			p[i] = temp.size();
		}
		else {
			temp[index] = arr[i];
			p[i] = index + 1;
		}
	}
	
	cout << temp.size() << '\n';

	int index = temp.size();
	for (int i = N; i > 0; i--) {
		if (p[i] == index) {
			index--;
			temp[index] = arr[i];
		}
	}

	for (int i = 0; i < temp.size(); i++) cout << temp[i] << " ";
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
}

int main() { //가장 긴 증가하는 부분 수열 4
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}