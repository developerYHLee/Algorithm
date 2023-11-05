#include <iostream>
#include <string>

using namespace std;

string get_num(int num, bool check) {
	string res = "";

	int* temp = new int[3];
	for (int i = 0; i < 3; i++) {
		temp[i] = num % 2;
		num /= 2;
	}

	for (int i = 2; i >= 0; i--) {
		if (!check && temp[i] == 0) continue;

		check = true;
		res += to_string(temp[i]);
	}

	return res;
}

int main(){ //8진수 2진수
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	string res = get_num(str[0] - '0', false);
	int N = str.size();
	for (int i = 1; i < N; i++) {
		int num = str[i] - '0';

		res += get_num(num, true);
	}

	cout << (res.size() == 0 ? "0" : res);
}