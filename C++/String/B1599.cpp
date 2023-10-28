#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> m_dic;
string str[50];

bool cmp(string o1, string o2) {
	int i1 = 0, i2 = 0;
	while (i1 < o1.size() && i2 < o2.size()) {
		string s1;
		s1 = o1[i1];

		if (s1.compare("n") == 0) {
			if (i1 < o1.size() - 1 && o1[i1 + 1] == 'g') {
				i1++;
				s1 += "g";
			}
		}

		string s2;
		s2 = o2[i2];
		
		if (s2.compare("n") == 0) {
			if (i2 < o2.size() - 1 && o2[i2 + 1] == 'g') {
				i2++;
				s2 += "g";
			}
		}

		int n1 = m_dic.find(s1)->second, n2 = m_dic.find(s2)->second;
		
		if (n1 > n2) return false;
		else if (n1 < n2) return true;

		i1++;
		i2++;
	}

	return o1.size() < o2.size();
}

void make_dic() {
	m_dic.insert({ "a", 0 });
	m_dic.insert({ "b", 1 });
	m_dic.insert({ "k", 2 });
	m_dic.insert({ "d", 3 });
	m_dic.insert({ "e", 4 });
	m_dic.insert({ "g", 5 });
	m_dic.insert({ "h", 6 });
	m_dic.insert({ "i", 7 });
	m_dic.insert({ "l", 8 });
	m_dic.insert({ "m", 9 });
	m_dic.insert({ "n", 10 });
	m_dic.insert({ "ng", 11 });
	m_dic.insert({ "o", 12 });
	m_dic.insert({ "p", 13 });
	m_dic.insert({ "r", 14 });
	m_dic.insert({ "s", 15 });
	m_dic.insert({ "t", 16 });
	m_dic.insert({ "u", 17 });
	m_dic.insert({ "w", 18 });
	m_dic.insert({ "y", 19 });
}

int main() { //¹Î½Ä¾î
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	make_dic();

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) cin >> str[i];
	sort(str, str + N, cmp);

	for (int i = 0; i < N; i++) cout << str[i] << '\n';
}