#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() { //크게 만들기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	string str;
	cin >> str;

	stack<int> S;
	
	int index = 0;
	for (int i = 0; i < str.size(); i++, index++) {
		int n = str[i] - '0';
		
		if (S.empty()) {
			S.push(n);
			continue;
		}

		int temp = S.top();
		while (temp < n) {
			S.pop();
			K--;

			if (K == 0 || S.empty()) break;
			temp = S.top();
		}
		if (K == 0) break;

		S.push(n);
	}

	for (int i = 0; i < K; i++) S.pop();

	string res = "";
	for (int i = str.size() - 1; i >= index; i--) res += str[i];

	while (!S.empty()) {
		int n = S.top();
		S.pop();

		res += '0' + n;
	}

	reverse(res.begin(), res.end());
	cout << res;
}