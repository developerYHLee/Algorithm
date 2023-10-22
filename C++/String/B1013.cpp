#include <iostream>
#include <string>

using namespace std;

string str;

inline bool solve2(int& index) {
	if (index == str.size()) return false;

	if (str[index++] == '1') return true;
	return false;
}

bool solve1(int& index) {
	if (index == str.size()) return false;

	if (str.substr(index, 2).compare("00") != 0) return false;
	
	index += 2;
	if (index == str.size()) return false;
	while (str[index] == '0') {
		index++;

		if (index == str.size()) return false;
	}
	
	index++;
	if (index == str.size()) return true;
	
	if (str[index] == '0') return true;
	while (str[index] == '1') {
		index++;
	
		if (index == str.size()) return true;
	}

	int tempIndex = index + 1;
	if (solve2(tempIndex)) index += 2;
	else index--;

	return true;
}

bool solve() {
	for (int i = 0; i < str.size();) {
		if (str[i] == '0') {
			if (!solve2(++i)) return false;
		}
		else {
			if (!solve1(++i)) return false;
		}
	}

	return true;
}

int main() { //Contact
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T-- > 0) {
		cin >> str;

		if (solve()) cout << "YES\n";
		else cout << "NO\n";
	}
}