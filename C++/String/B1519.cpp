#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int dp[1000001];

void solve(int index) { //1번 - 1초 미만
	int MIN = 1e9;
	for (int i = 10; i <= index; i *= 10) {
		int temp = index;
	
		while (temp > 0) {
			int m = temp % i;
			temp /= 10;

			if (m > 0 && !dp[index - m]) MIN = min(MIN, m);
		}
	}

	dp[index] = (MIN == 1e9 ? 0 : MIN);
}

/*
void solve(int index, string str) { //2번 - 16~17초
	int MIN = 1e9;

	for (int i = 0; i < str.size(); i++) {
		string temp = "";
		for (int j = i; j < str.size(); j++) {
			temp += str[j];
			int n = stoi(temp);
			if (n == 0 || n == index) continue;

			if (!dp[index - n]) MIN = min(MIN, n);
		}
	}

	dp[index] = MIN == 1e9 ? 0 : MIN;
}
*/

int main() { //부분 문자열 뽑기 게임
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	/*
	time_t s, e;
	s = time(NULL);
	for (int i = 10; i <= N; i++) {
		//solve(i);
		solve(i, to_string(i));
	}
	e = time(NULL);

	cout << (double)(e - s) << " second" << endl;
	*/
	
	for(int i = 10; i <= N; i++) solve(i);
	cout << (dp[N] == 0 ? -1 : dp[N]);
}