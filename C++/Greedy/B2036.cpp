#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

ll solve(priority_queue<int>& PQ, bool isP) {
	ll ret = 0;

	while (!PQ.empty()) {
		ll n1 = PQ.top();
		PQ.pop();

		if (PQ.empty()) {
			if (isP) ret += n1;
			else ret -= n1;

			break;
		}

		ll n2 = PQ.top();
		PQ.pop();

		if (!isP || n2 != 1) ret += n1 * n2;
		else ret += n1 + n2;
	}

	return ret;
}
int main() { //수열의 점수
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	priority_queue<int> p, m;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		
		if (num > 0) p.push(num);
		else m.push(-num);
	}

	cout << (solve(p, true) + solve(m, false));
}