#include <iostream>

using namespace std;

int N, arr[10];
bool vis[10];

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		for (int j = 0; j < N; j++) {
			if (vis[j]) continue;
			if (!num) {
				vis[j] = true;
				arr[j] = i + 1;
				break;
			}

			num--;
		}
	}
}

int main() { //한 줄로 서기
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	for (int i = 0; i < N; i++) cout << arr[i] << " ";
}