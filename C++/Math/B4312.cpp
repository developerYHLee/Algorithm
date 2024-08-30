#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef unsigned long long ull;

ull N;
string dp[100];
vector<string> res;

string mulNum(string str, int x) {
	string ret = "";
	int o = 0;

	for (int i = str.size() - 1; i >= 0; i--) {
		int n = str[i] - '0';
		n = n * x + o;
		
		o = n / 10;
		n = n % 10;
		
		ret += n + '0';
	}
	
	if (o) ret += o + '0';

	reverse(ret.begin(), ret.end());

	return ret;
}

void setDp() {
	dp[0] = "1";
	for (int i = 1; i < 100; i++) dp[i] = mulNum(dp[i - 1], 3);
}

int getP() {
	int p = 0;
	ull tempN = 1;
	while (tempN <= N) {
		tempN *= 2;
		p++;
	}

	tempN /= 2;
	N -= tempN;

	return p - 1;
}

void solve() {
	N--;
	while (N) {
		int p = getP();
		res.push_back(dp[p]);
	}

	cout << "{ ";
	for (int i = (int)res.size() - 1; i >= 1; i--) cout << res[i] << ", ";
	if(res.size() > 0) cout << res[0] << " ";
	cout << "}\n";
}

int main() { //3ÀÇ Á¦°ö
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	setDp();
	cin >> N;
	while (N) {
		solve();
		res.clear();
		cin >> N;
	}
}