#include <iostream>
#include <memory.h>
#include <cmath>

using namespace std;

bool B[10]; //베이스
int P[50][10]; //이닝 별 플레이어 타격
int H[10]; //타순
bool vis[10];
int N, res;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 1; j <= 9; j++) cin >> P[i][j];
	}
}

void ChangeBase(int& s, int n) {
	for (int i = n; i <= 3; i++) { //n번째 베이스까지 득점
		if (B[i]) {
			B[i] = false;
			s++;
		}
	}
	for (int i = n - 1; i > 0; i--) { //n번째 베이스 전까지 진루
		if (B[i]) {
			B[i] = false;
			B[i + 3 - n + 1] = true;
		}
	}
}

void CheckHit(int index, int p, int& o, int& s) {
	if (P[index][p] == 0) o++; //아웃
	else if (P[index][p] == 1) { //1루타
		ChangeBase(s, 3);
		B[1] = true;
	}
	else if (P[index][p] == 2) { //2루타
		ChangeBase(s, 2);
		B[2] = true;
	}
	else if (P[index][p] == 3) { //3루타
		ChangeBase(s, 1);
		B[3] = true;
	}
	else if (P[index][p] == 4) { //홈런
		ChangeBase(s, 1);
		s++;
	}
}

int calScore() {
	int h = 1; //현재 타순
	int s = 0; //점수

	for (int i = 0; i < N; i++) {
		int o = 0; //아웃

		while (o < 3) {
			CheckHit(i, H[h++], o, s); //타격 확인
			if (h == 10) h = 1;
		}

		memset(B, false, 4);
	}

	return s;
}

//타순을 정하고 얻을 점수를 계산 후 최대 득점과 비교
void backtracking(int index) {
	if (index == 10) {
		res = max(res, calScore());
		return;
	}

	if (index == 4) {
		backtracking(index + 1);
		return;
	}

	for (int i = 1; i <= 9; i++) {
		if (vis[i]) continue;

		H[index] = i;
		vis[i] = true;
		backtracking(index + 1);
		vis[i] = false;
	}
}

void solve() {
	H[4] = 1;
	vis[1] = true;
	backtracking(1);
	
	cout << res;
}

int main() { //⚾
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}