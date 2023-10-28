#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;

pii alpha[26];
int num[26];

void make_alpha(string str) {
	int n = str.size() - 1;
	for (int i = 0; i <= n; i++) alpha[str[i] - 'A'].first += (int)pow(10, n - i);
}

void get_num() {
	for (int i = 0, n = 9; alpha[i].first > 0; i++, n--) num[alpha[i].second] = n;
}

int get_res(string str) {
	string res = "";
	for (int i = 0; i < str.size(); i++) res += num[str[i] - 'A'] + '0';
	
	return stoi(res);
}

int main() { //단어 수학
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 26; i++) alpha[i] = { 0, i };

	int N;
	cin >> N;
	string word[11];
	for (int i = 0; i < N; i++) {
		cin >> word[i];
		make_alpha(word[i]);
	}
	sort(alpha, alpha + 26, greater<pii>());
	fill_n(num, 26, -1);
	get_num();
	
	int res = 0;
	for (int i = 0; i < N; i++) res += get_res(word[i]);
	cout << res;

}