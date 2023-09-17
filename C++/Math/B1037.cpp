#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	
	vector<int> list;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		list.push_back(num);
	}

	sort(list.begin(), list.end());
	cout << list[0] * list[N - 1];
}