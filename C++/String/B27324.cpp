#include <iostream>

using namespace std;

int main() { //«¾«íÙÍ (Same Numbers)
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;
	
	cout << (str[0] == str[1] ? "1" : "0");
}