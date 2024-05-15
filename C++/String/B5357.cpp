#include <iostream>

using namespace std;

int main() { //Dedupe
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		string res;
		res = str[0];

		for (int j = 1; j < str.length(); j++) {
			if (str[j - 1] == str[j]) continue;
			res += str[j];
		}

		cout << res << "\n";
	}
}