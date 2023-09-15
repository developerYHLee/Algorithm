#include <iostream>
#include <numeric>
using namespace std;

int MOD = 1000000007;
long long A(long long num, int K) {
	if (K == 1) return num;

	long long tempA = A(num, K / 2);
	tempA = tempA * tempA % MOD;

	if (K % 2 == 1) tempA = tempA * num % MOD;

	return tempA;
}

long long make_gcd(long long a, long long b) {
	while (b > 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}

	return a;
}

int main() { //¥Ò
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M;
	cin >> M;

	long long sum = 0;
	for (int i = 0; i < M; i++) {
		long long a, b;

		cin >> b >> a;
		long long GCD = make_gcd(a, b);

		a /= GCD;
		b /= GCD;

		b = A(b, MOD - 2);

		sum += a * b % MOD;
	}

	cout << sum % MOD;
}