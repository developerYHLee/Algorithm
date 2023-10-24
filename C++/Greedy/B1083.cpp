#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; i++) cin >> arr[i];
	
	int S;
	cin >> S;

	vector<int> res;
	if (S >= N * (N - 1) / 2) {
		sort(arr.begin(), arr.end(), greater());
		for (int i = 0; i < N; i++) res.push_back(arr[i]);
	}
	else {
		while (true) {
			int tempN = arr.size();
			if (tempN == 0 || S <= 0) break;

			int tempS = 0, MAX = arr[0], index = 0;
			for (int j = 1; j < tempN; j++) {
				tempS++;

				if (tempS > S) break;
				if (MAX < arr[j]) {
					MAX = arr[j];
					index = j;
				}
			}

			res.push_back(MAX);
			arr.erase(arr.begin() + index);
			S -= index;
		}

		for (int i = 0; i < arr.size(); i++) res.push_back(arr[i]);
	}

	for (int i = 0; i < N; i++) cout << res[i] << " ";
}