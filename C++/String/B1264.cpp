#include <iostream>
#include <string>

using namespace std;

int main() { //모음의 개수
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	getline(cin, str);

	while (str.compare("#") != 0) {
		int res = 0;

		for (int i = 0; i < str.size(); i++) {
			switch (str[i])
			{
				case 'a':
				case 'A':
				case 'e':
				case 'E':
				case 'i':
				case 'I':
				case 'o':
				case 'O':
				case 'u':
				case 'U':
					res++;
					break;
			}
		}
		cout << res << '\n';
		getline(cin, str);
	}
}