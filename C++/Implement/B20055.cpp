#include <iostream>

using namespace std;

int N, K, belt[200];
bool robot[200];

void input() {
	cin >> N >> K;
	for (int i = 0; i < N * 2; i++) cin >> belt[i];
}

bool check() {
	int cnt = 0;
	for (int i = 0; i < 2 * N; i++) {
		if (!belt[i]) cnt++;
	}

	if (cnt >= K) return false;
	else return true;
}

void rotate() {
	int prevB = belt[0];
	bool prevR = robot[0];

	for (int i = 1; i < 2 * N; i++) {
		int tempB = belt[i];
		belt[i] = prevB;
		prevB = tempB;

		bool tempR = robot[i];
		robot[i] = prevR;
		prevR = tempR;
	}

	belt[0] = prevB;
	robot[0] = prevR;

	robot[N - 1] = false;
}

void move() {
	for (int i = N - 2; i > 0; i--) {
		if (robot[i] && !robot[i + 1] && belt[i + 1]) {
			belt[i + 1]--;
			robot[i + 1] = true;
			robot[i] = false;
		}
	}
	robot[N - 1] = false;
}

void putRobot() {
	if (belt[0]) {
		belt[0]--;
		robot[0] = true;
	}
}

void solve() {
	int res = 0;

	while (true) {
		res++;
		rotate();
		move();
		putRobot();

		if (!check()) break;
	}
	
	cout << res;
}

int main() { //컨베이어 벨트 위의 로봇
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}