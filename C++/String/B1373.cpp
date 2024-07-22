#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() { //2진수 8진수
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string str, res = "";
	cin >> str;

	for (int i = str.size() - 1; i >= 0; i -= 3) {
		int num = 0, cnt = 0;

		for (int j = i; j - cnt >= 0 && cnt < 3; cnt++) {
			num += ((1 << (i - j + cnt)) * (str[j - cnt] - '0'));
		}

		res += to_string(num);
	}
	reverse(res.begin(), res.end());
	cout << res;
}