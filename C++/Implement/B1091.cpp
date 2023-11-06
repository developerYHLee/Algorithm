#include <iostream>

using namespace std;

int N, P[48], S[48];

inline void shuffle_card(int* s, int* temp) {
	for (int i = 0; i < N; i++) temp[i] = S[s[i]];
}

inline bool check_P(int* s) {
	bool ret = true;
	
	for (int i = 0; i < N; i++) {
		if (s[i] % 3 != P[i]) ret = false;
	}

	return ret;
}

bool check_S(int* s) {
	bool ret = false;

	for (int i = 0; i < N; i++) {
		if (s[i] != S[i]) ret = true;
	}

	return ret;
}

void print_s(int* s1, int* s2) {
	cout << "s1 : ";
	for (int i = 0; i < N; i++) cout << s1[i] << ' ';
	cout << '\n';

	cout << "s2 : ";
	for (int i = 0; i < N; i++) cout << s2[i] << ' ';
	cout << '\n';
}

int main() { //Ä«µå ¼¯±â
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> P[i];
	for (int i = 0; i < N; i++) cin >> S[i];

	int* s1 = new int[N] {}, * s2 = new int[N] {};
	for (int i = 1; i < N; i++) {
		s1[i] = i;
		s2[i] = (s2[i - 1] + 1) % 3;
	}

	if (check_P(s2)) {
		cout << 0;
		return 0;
	}
	shuffle_card(s1, s2);

	if (check_P(s2)) {
		cout << 1;
		return 0;
	}
	shuffle_card(s2, s1);

	int count = 2;
	bool c = true;
	while (true) {
		if (c) {
			c = false;

			if (check_P(s1)) break;
			shuffle_card(s1, s2);

			if (!check_S(s2)) {
				cout << -1;
				return 0;
			}
		}
		else {
			c = true;

			if (check_P(s2)) break;
			shuffle_card(s2, s1);

			if (!check_S(s1)) {
				cout << -1;
				return 0;
			}
		}

		count++;
	}

	cout << count;
}