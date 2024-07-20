#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, _max;
string name;
vector<string> str;

void input() {
	cin >> name >> N;

	int love[4]{ 0, };
	for (int i = 0; i < name.size(); i++) {
		if (name[i] == 'L') love[0]++;
		else if (name[i] == 'O') love[1]++;
		else if (name[i] == 'V') love[2]++;
		else if (name[i] == 'E') love[3]++;
	}

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;

		int tempLove[4]{ love[0], love[1], love[2], love[3] };
		for (int j = 0; j < temp.size(); j++) {
			if (temp[j] == 'L') tempLove[0]++;
			else if (temp[j] == 'O') tempLove[1]++;
			else if (temp[j] == 'V') tempLove[2]++;
			else if (temp[j] == 'E') tempLove[3]++;
		}

		int cnt = tempLove[2] + tempLove[3];
		for (int j = 0; j < 2; j++) {
			for (int k = j + 1; k < 4; k++) cnt *= tempLove[j] + tempLove[k];
		}
		cnt %= 100;

		if (_max <= cnt) {
			if (_max < cnt) {
				_max = cnt;
				str.clear();
			}
			str.push_back(temp);
		}
	}
}

int main() { //팀 이름 정하기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	sort(str.begin(), str.end());
	cout << str[0];
}