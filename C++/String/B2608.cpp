#include <iostream>

using namespace std;

int to_num(char roma) {
	if (roma == 'I') return 1;
	else if (roma == 'V') return 5;
	else if (roma == 'X') return 10;
	else if (roma == 'L') return 50;
	else if (roma == 'C') return 100;
	else if (roma == 'D') return 500;
	else if (roma == 'M') return 1000;
}

void cal_num(int& num, int m, string& str, string roma) {
	while (num >= m) {
		num -= m;
		str += roma;
	}
}

string to_roma(int num) {
	string ret = "";

	cal_num(num, 1000, ret, "M");
	cal_num(num, 900, ret, "CM");
	cal_num(num, 500, ret, "D");
	cal_num(num, 400, ret, "CD");
	cal_num(num, 100, ret, "C");
	cal_num(num, 90, ret, "XC");
	cal_num(num, 50, ret, "L");
	cal_num(num, 40, ret, "XL");
	cal_num(num, 10, ret, "X");
	cal_num(num, 9, ret, "IX");
	cal_num(num, 5, ret, "V");
	cal_num(num, 4, ret, "IV");
	cal_num(num, 1, ret, "I");

	return ret;
}

int get_num(string str) {
	int ret = 0, i = 0;

	while (i < str.size() - 1) {
		int n1 = to_num(str[i]), n2 = to_num(str[i + 1]);

		if (n1 < n2) {
			ret += n2 - n1;
			i += 2;
		}
		else {
			ret += n1;
			i++;
		}
	}
	if (i == str.size() - 1) ret += to_num(str[i]);

	return ret;
}

int main() { //로마 숫자
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str1, str2;
	cin >> str1 >> str2;

	int num = get_num(str1) + get_num(str2);
	cout << num << '\n' << to_roma(num);
}