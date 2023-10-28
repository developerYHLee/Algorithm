#include <iostream>

using namespace std;

int dp[3000001];
int main() { //���� ���� ����� �������� ���ٴ�
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int L;
	cin >> L;

	int ML, MK;
	cin >> ML >> MK;

	int C;
	cin >> C;

	string res = "YES";
	for (int i = 1; i <= L; i++) {
		int zombie;
		cin >> zombie;

		int n = dp[i - 1] - dp[max(0, i - ML)];
		if (zombie - n > MK) {
			if (C) {
				C--;
				dp[i] = dp[i - 1];
			}
			else res = "NO";
		}
		else dp[i] = dp[i - 1] + MK;
	}

	cout << res;
}