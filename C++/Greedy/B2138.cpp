#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int N, res;
string currentState, goal;

void input() {
	cin >> N >> currentState >> goal;
	res = INT_MAX;
}

void printRes() {
	cout << (res == INT_MAX ? -1 : res);
}

void toggle(string& temp, int index) {
	temp[index] = temp[index] == '0' ? '1' : '0';
}

void solve(bool ch) {
	int cnt = 0;
	string temp = currentState;

	if (ch) {
		toggle(temp, 0);
		toggle(temp, 1);
		cnt++;
	}
	
	for (int i = 1; i < N; i++) {
		if (temp[i - 1] != goal[i - 1]) {
			toggle(temp, i - 1);
			toggle(temp, i);
			if(i < N - 1) toggle(temp, i + 1);
			cnt++;
		}
	}

	if (!temp.compare(goal)) res = min(res, cnt);
}

int main() { //전구와 스위치
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve(false);
	solve(true);
	printRes();
}