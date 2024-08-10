#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() { //단어 뒤집기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	cin.ignore();

	while (N--) {
		string str;
		getline(cin, str);
		
		stringstream ss(str);
		string temp;

		while (ss >> temp) {
			reverse(temp.begin(), temp.end());
			cout << temp << " ";
		}
		cout << "\n";
	}
}