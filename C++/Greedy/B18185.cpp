#include <iostream>
#include <cmath>

using namespace std;

int A[10001];

int main() { //라면 사기 (Small)
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) cin >> A[i];

	int* num = new int[3];
	int cost = 0;
	for (int i = 0, co = 0; i <= N; i++) {
		if (co == 3) {
			if (A[i - 2] <= A[i - 1]) {
				int m = min(A[i - 3], min(A[i - 2], A[i - 1]));
				
				for (int j = 1; j <= 3; j++) A[i - j] -= m;
				cost += m * 7;

				if (A[i - 3] > 0) {
					cost += A[i - 3] * 3;
					A[i - 3] = 0;
				}
				i -= 3;
			}
			else {
				while (A[i - 3] > 0 && A[i - 2] > A[i - 1]) {
					cost += 5;
					A[i - 3]--;
					A[i - 2]--;
				}

				if (A[i - 3] > 0) i -= 4;
				else if (A[i - 2] > 0) i -= 3;
			}

			co = 0;
			continue;
		}

		if (A[i] == 0) {
			if(co == 0) continue;
			else if (co == 1) {
				cost += A[i - 1] * 3;
				A[i - 1] = 0;
			}
			else {
				int m = A[i - 1], next;
				if (A[i - 1] < A[i - 2]) next = i - 3;
				else if (A[i - 1] > A[i - 2]) {
					m = A[i - 2];
					next = i - 2;
				}

				cost += m * 5;
				A[i - 2] -= m;
				A[i - 1] -= m;
				i = next;
			}

			co = 0;
			continue;
		}

		num[co++] = A[i];
	}

	delete[] num;
	cout << cost;
}