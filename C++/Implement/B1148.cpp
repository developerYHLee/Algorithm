#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

vector<vector<pii>> alphas;

void print_vector (const vector<int>& v) {
	for (int i = 0; i < 26; i++) cout << (char)(i + 'A') << " " << v[i] << endl;
}

int main() { //�ܾ� �����
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	while (str[0] != '-') {
		vector<int> temp(26);

		int N = str.size();
		for (int i = 0; i < N; i++) temp[str[i] - 'A']++;
		
		vector<pii> alpha;
		for (int i = 0; i < 26; i++) {
			if (temp[i] > 0) alpha.push_back({ i, temp[i] });
		}
		
		alphas.push_back(alpha);
		cin >> str;
	}

	cin >> str;
	while (str[0] != '#') {
		int N = alphas.size();

		vector<int> puzzle(26), alpha_count(26);
		
		//puzzle�� ����ִ� ���ĺ� ī��Ʈ
		int M = str.size();
		for (int i = 0; i < M; i++) puzzle[str[i] - 'A']++;

		//�˻� ����
		for (vector<pii> alpha : alphas) {
			vector<int> temp;
			bool check = true;
			
			//�ܾ�� �˻�
			for (pii a : alpha) {
				int i = a.first, c = a.second;

				//�ܾ �ִ� ���ĺ��� ������ �� ������ ����
				if (puzzle[i] < c) {
					check = false;
					break;
				}

				temp.push_back(i);
			}

			if (check) {
				for (int i : temp) alpha_count[i]++;
			}
		}


		string ans1 = "", ans2 = "";
		int m1 = 0, m2 = 1e9; //m1�� �ִ�, m2�� �ּ�
		for (int i = 0; i < 26; i++) {
			if (puzzle[i] > 0) {
				char a = (char)(i + 'A');

				if (m1 < alpha_count[i]) {
					m1 = alpha_count[i];
					ans1 = a;
				}
				else if (m1 == alpha_count[i]) ans1 += a;
			
				if (m2 > alpha_count[i]) {
					m2 = alpha_count[i];
					ans2 = a;
				}
				else if (m2 == alpha_count[i]) ans2 += a;
			}
		}

		cout << ans2 << " " << m2 << " " << ans1 << " " << m1 << endl;
	
		cin >> str;
	}
}