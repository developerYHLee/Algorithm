#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main() { //전생했더니 슬라임 연구자였던 건에 대하여 (Hard)
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;

	while (T-- > 0) {
		int N;
		cin >> N;

		priority_queue<ll, vector<ll>, greater<ll>> PQ;
		while (N-- > 0) {
			ll slime;
			cin >> slime;

			PQ.push(slime);
		}

		ll sum = 1;
		while (PQ.size() > 1) {
			ll s1 = PQ.top();
			PQ.pop();

			ll s2 = PQ.top();
			PQ.pop();

			ll new_s = s1 * s2;
			sum *= new_s % MOD;
			sum %= MOD;

			PQ.push(new_s);
		}

		cout << sum << '\n';
	}
}