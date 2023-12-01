#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() { //토너먼트 만들기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> V(N);
	for (int i = 0; i < N; i++) cin >> V[i];

	int res = 0;
	while (V.size() > 1) {
		int max_index = 0;
		for (int i = 1; i < V.size(); i++) {
			if (V[i] > V[max_index]) max_index = i;
		}
		
		int n1 = max_index, n2 = max_index, n3 = max_index;
		if (max_index > 0 && max_index < V.size() - 1) {
			n1--;
			n3++;
		}
		else if (!max_index) n3++;
		else n1--;

		int x = abs(V[n1] - V[n2]), y = abs(V[n2] - V[n3]);
		if (!x) res += y;
		else if (!y) res += x;
		else res += min(x, y);

		V.erase(V.begin() + max_index);
	}

	cout << res;
}