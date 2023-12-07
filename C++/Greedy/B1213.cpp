#include <iostream>

using namespace std;

int alpha[26];
int main() { //�Ӹ���� �����
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) alpha[str[i] - 'A']++;

	int l = 0, r = str.size() - 1;
	bool isEven = str.size() % 2 == 0;
	
	//A���� Z���� Ž��
	for (int i = 0; i < 26; i++) {
		if (!alpha[i]) continue;

		//Ž���ϰ� �ִ� ���ĺ��� Ȧ���� ��, ���� ���ڿ��� ���̰� ¦����� �Ӹ���� �Ұ�
		//���� ���ڿ��� ���̰� Ȧ����� ����� ä���ΰ� �ٽ� Ž��
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
		
			//������ Ž���ϰ� �ִ� ���ĺ����� ä��
			for (int j = 0; j < cnt; j++) {
				str[l++] = i + 'A';
				str[r--] = i + 'A';
			}
		}
	}
	
	cout << str;
}