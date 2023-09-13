#include <iostream>
#include <vector>

using namespace std;

int main() { //피보나치 수
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> dp;
	dp.push_back(0);
	dp.push_back(1);

	for (int i = 2; i <= N; i++) dp.push_back(dp[i - 1] + dp[i - 2]);
	cout << dp[N];
}
