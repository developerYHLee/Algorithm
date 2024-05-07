#include <iostream>
#include <string>

using namespace std;

int main() { //Football Team
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;

	while(getline(cin, str)) {
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == 'i') str[j] = 'e';
			else if (str[j] == 'e') str[j] = 'i';
			else if (str[j] == 'I') str[j] = 'E';
			else if (str[j] == 'E') str[j] = 'I';
		}

		cout << str << "\n";
	}
}