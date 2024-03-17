#include <iostream>
#include <string>

using namespace std;

int main() { //Gum Gum for Jay Jay
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	
	int cnt = 0;
	while (getline(cin, str)) cnt++;
	cout << cnt;
}