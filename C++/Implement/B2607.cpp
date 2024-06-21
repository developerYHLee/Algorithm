#include <iostream>

using namespace std;

int N, alpha[26], res;

void countWord(const string& str) {
	int temp[26]{};
	
	for (char a : str) temp[a - 'A']++;

	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] - temp[i] == 0) continue;
		else if (alpha[i] == temp[i] + 1) {
			if (!cnt) cnt++;
			else if (cnt == -1) cnt--;
			else return;
		}
		else if (alpha[i] + 1 == temp[i]) {
			if (!cnt) cnt--;
			else if (cnt == 1) cnt++;
			else return;
		}
		else return;
	}

	res++;
}

void input() {
	string str;

	cin >> N >> str;
	for (char a : str) alpha[a - 'A']++;
	for (int i = 1; i < N; i++) {
		cin >> str;

		countWord(str);
	}
}

int main() { //비슷한 단어
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	cout << res;
}