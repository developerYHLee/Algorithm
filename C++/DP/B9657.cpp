#include <iostream>

using namespace std;

bool SK[1001];
int main() { //µ¹ °ÔÀÓ 3 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	SK[1] = true;
	SK[2] = false;
	SK[3] = true;
	SK[4] = true;

	for (int i = 5; i <= 1000; i++) {
		if (!SK[i - 1] || !SK[i - 3] || !SK[i - 4]) SK[i] = true;
	}

	cout << (SK[N] ? "SK" : "CY");
}