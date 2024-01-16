#include <iostream>
#include <string>
#include <sstream>

using namespace std;

double get_score(string s) {
	if (!s.compare("A+")) return 4.5;
	else if (!s.compare("A0")) return 4.0;
	else if (!s.compare("B+")) return 3.5;
	else if (!s.compare("B0")) return 3.0;
	else if (!s.compare("C+")) return 2.5;
	else if (!s.compare("C0")) return 2.0;
	else if (!s.compare("D+")) return 1.5;
	else if (!s.compare("D0")) return 1.0;
	else if (!s.compare("F")) return 0.0;

	return -1;
}

int main() { //너의 평점은
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	double sum = 0;
	int cnt = 0;
	string str;	
	while (getline(cin, str)) {
		istringstream iss(str);
		string temp[3];
		for (int i = 0; i < 3; i++) iss >> temp[i];

		int p = temp[1][0] - '0';
		double s = get_score(temp[2]);

		if (s == -1) continue;

		cnt += p;
		sum += p * s;
	}

	cout << sum / cnt;
}