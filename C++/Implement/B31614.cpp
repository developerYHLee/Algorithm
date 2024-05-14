#include <iostream>

using namespace std;

int main() { //ÝÂ (Minutes)
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int H, M;
	cin >> H >> M;
	cout << H * 60 + M;
}