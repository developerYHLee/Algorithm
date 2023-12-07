#include <iostream>

using namespace std;

int alpha[26];
int main() { //팰린드롬 만들기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) alpha[str[i] - 'A']++;

	int l = 0, r = str.size() - 1;
	bool isEven = str.size() % 2 == 0;
	
	//A부터 Z까지 탐색
	for (int i = 0; i < 26; i++) {
		if (!alpha[i]) continue;

		//탐색하고 있는 알파벳이 홀수일 때, 남은 문자열의 길이가 짝수라면 팰린드롬 불가
		//남은 문자열의 길이가 홀수라면 가운데를 채워두고 다시 탐색
		if (alpha[i] % 2 != 0) {
			if (isEven) {
				cout << "I'm Sorry Hansoo";
				return 0;
			}

			isEven = true;
			str[str.size() / 2] = i + 'A';
			alpha[i--]--;
		}
		else {
			int cnt = alpha[i] / 2;
		
			//양쪽을 탐색하고 있는 알파벳으로 채움
			for (int j = 0; j < cnt; j++) {
				str[l++] = i + 'A';
				str[r--] = i + 'A';
			}
		}
	}
	
	cout << str;
}