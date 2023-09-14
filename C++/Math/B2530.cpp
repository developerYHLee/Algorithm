#include <iostream>

using namespace std;

int main() { //인공지능 시계
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cur_H, cur_M, cur_S;
	cin >> cur_H >> cur_M >> cur_S;

	int s;
	cin >> s;

	int h, m;

	m = s / 60;
	s %= 60;

	h = m / 60;
	m %= 60;

	cur_S = cur_S + s;
	if (cur_S >= 60) {
		cur_S -= 60;
		cur_M++;
	}

	cur_M = cur_M + m;
	if (cur_M >= 60) {
		cur_M -= 60;
		cur_H++;
	}

	cur_H = cur_H + h;
	if (cur_H >= 24) cur_H %= 24;
	
	cout << cur_H << " " << cur_M << " " << cur_S;
}