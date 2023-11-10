#include <iostream>
#include <regex>

using namespace std;

int main() { //잠수함식별
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	regex pattern("(100+1+|01)+");
	cout << (regex_match(str, pattern) ? "SUBMARINE\n" : "NOISE\n");
}