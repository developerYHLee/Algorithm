#include <iostream>
#include <stack>

using namespace std;

int main() { //Æ÷½ºÅÃ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	stack<int> S[4];
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		for (int i = 0; i <= 4; i++) {
			if (i == 4) {
				cout << "NO";
				return 0;
			}

			if (S[i].empty() || S[i].top() < num) {
				S[i].push(num);
				break;
			}
		}
	}

	cout << "YES";
}