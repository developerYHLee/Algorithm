#include <iostream>
#include <regex>

using namespace std;

int main() { //¹ö±×¿Õ
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	
	regex pattern("(BUG)+");
	while (getline(cin, str)) {
		while(regex_search(str, pattern)) str = regex_replace(str, pattern, "");
		cout << str << endl;
	}
}