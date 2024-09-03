#include <iostream>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;

const int MAX = 1'000'001;
ll A, B, L;
unordered_map<int, int> prime;
bool notPrime[MAX];

void eratos() {
	notPrime[1] = true;
	for (int i = 2; i * i < MAX; i++) {
		if (notPrime[i]) continue;

		for (int j = i + i; j < MAX; j += i) notPrime[j] = true;
	}
}

ll getGCD(ll x, ll y) {
	while (x) {
		ll temp = x;
		x = y % x;
		y = temp;
	}

	return y;
}

int checkPrime(ll n1, int n2) {
	if (notPrime[n2]) return 0;

	int cnt = 0;
	while (n1 % n2 == 0) {
		n1 /= n2;
		cnt++;
	}

	return cnt;
}

void setLCD(ll num) {
	int sqrtNum = (int)sqrt(num);

	for (int i = 1; i <= sqrtNum; i++) {
		if (num % i != 0) continue;

		if(num / i < MAX) prime[num / i] = checkPrime(num, num / i);
		if((ll)i * i != num) prime[i] = checkPrime(num, i);
	}
}

void input() {
	cin >> A >> B >> L;
}

void solve() {
	eratos();
	ll LCM = A * B / getGCD(A, B);
	setLCD(LCM);

	if (L % LCM != 0) {
		cout << -1;
		return;
	}

	ll res = L / LCM;
	int sqrtNum = (int)sqrt(L);

	for (int i = 1; i <= sqrtNum; i++) {
		if (L % i != 0) continue;

		if (L / i < MAX) {
			int cnt = checkPrime(L, L / i);
			if (prime[L / i] < cnt) res *= (ll)pow(L / i, prime[L / i]);
		}

		if ((ll)i * i != L) {
			int cnt = checkPrime(L, i);
			if (prime[i] < cnt) res *= (ll)pow(i, prime[i]);
		}
	}

	cout << res;
}

int main() { //최소공배수 찾기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}