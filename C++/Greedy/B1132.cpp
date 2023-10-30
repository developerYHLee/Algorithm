#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

bool s[10];
ll a_num[10];
vector<pli> alpha(10);

void get_alpha(string str) {
	int str_size = str.size() - 1;
	for (int i = 0; i <= str_size; i++) {
		int num = str[i] - 'A';
		alpha[num].first += (ll)pow(10, str_size - i);
	}

	s[str[0] - 'A'] = true;
}

void get_a_num() {
	int num = 1, index = -1, alpha_size = alpha.size();

	for (int i = 0; i < alpha_size; i++) {
		int a = alpha[i].second;
		
		if (!s[a]) {
			index = a;
			break;
		}
	}
	
	for (int i = 0; i < alpha_size; i++) {
		int a = alpha[i].second;

		if (index != a) a_num[a] = num++;
	}
}

ll get_num(string str) {
	int str_size = str.size();
	string res = "";

	for (int i = 0; i < str_size; i++) {
		int num = a_num[str[i] - 'A'];
		res += to_string(num);
	}

	return stoll(res);
}

int main() { //гу
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	
	for (int i = 0; i < 10; i++) alpha[i] = { 0, i };

	string* str = new string[N];
	for (int i = 0; i < N; i++) {
		cin >> str[i];
		get_alpha(str[i]);
	}
	sort(alpha.begin(), alpha.end());
	get_a_num();

	ll res = 0;
	for (int i = 0; i < N; i++) res += get_num(str[i]);
	cout << res;

	delete[] str;
}