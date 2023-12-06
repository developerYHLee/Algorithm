#include <iostream>
#include <sstream>

using namespace std;

char UCPC[4] = { 'U', 'C', 'P', 'C' };
int main() { //UCPC는 무엇의 약자일까?
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str, next;
	getline(cin, str);

	istringstream iss(str);
	int cnt = 0;
	while (iss >> next && cnt < 4) {
		for (int i = 0; i < next.size(); i++) {
			if (next[i] == UCPC[cnt]) cnt++;
			if (cnt == 4) {
				cout << "I love UCPC";
				return 0;
			}
		}
	}

	cout << "I hate UCPC";
}