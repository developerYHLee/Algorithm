#include <iostream>
#include <vector>

using namespace std;

int num[2001];
bool palindrome[2001][2001];

void solve(int N) {
	//바로 옆의 숫자
	for(int i = 1; i < N; i++) palindrome[i][i + 1] = (num[i] == num[i + 1]);

	//i만큼 떨어져 있는 숫자열
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j + i <= N; j++) palindrome[j][j + i] = (palindrome[j + 1][j + i - 1]) && (num[j] == num[j + i]);
	}
}

int main() { //팰린드롬?
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		palindrome[i][i] = true;
	}
	solve(N);

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;

		if (palindrome[s][e]) cout << "1\n";
		else cout << "0\n";
	}
}