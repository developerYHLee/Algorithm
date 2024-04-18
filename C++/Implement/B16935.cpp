#include <iostream>

using namespace std;

int N, M, R, arr[100][100], temp[100][100];

void input() {
	cin >> N >> M >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> arr[i][j];
	} 
}

void copyArr() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) temp[i][j] = arr[i][j];
	}
}

void moveUp(int szN, int szM, int startCol) {
	for (int i = 0; i < szN; i++) {
		for (int j = 0; j < szM; j++) arr[i][j + startCol] = temp[i + szN][j + startCol];
	}
}

void moveDown(int szN, int szM, int startCol) {
	for (int i = 0; i < szN; i++) {
		for (int j = 0; j < szM; j++) arr[i + szN][j + startCol] = temp[i][j + startCol];
	}
}

void moveRight(int szN, int szM, int startRow) {
	for (int i = 0; i < szN; i++) {
		for (int j = 0; j < szM; j++) arr[i + startRow][j + szM] = temp[i + startRow][j];
	}
}

void moveLeft(int szN, int szM, int startRow) {
	for (int i = 0; i < szN; i++) {
		for (int j = 0; j < szM; j++) arr[i + startRow][j] = temp[i + startRow][j + szM];
	}
}

void upDownMirror() {
	copyArr();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) arr[N - 1 - i][j] = temp[i][j];
	}
}

void sideMirror() {
	copyArr();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) arr[i][M - 1 - j] = temp[i][j];
	}
}

void rot() {
	copyArr();

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) arr[i][j] = temp[N - 1 - j][i];
	}
	swap(N, M);
}

void reverseRot() {
	copyArr();

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) arr[i][j] = temp[j][M - 1 - i];
	}
	swap(N, M);
}

void orderFive() {
	copyArr();

	int szN = N / 2, szM = M / 2;
	moveUp(szN, szM, 0);
	moveDown(szN, szM, szM);
	moveRight(szN, szM, 0);
	moveLeft(szN, szM, szN);
}

void orderSix() {
	copyArr();

	int szN = N / 2, szM = M / 2;
	moveUp(szN, szM, szM);
	moveDown(szN, szM, 0);
	moveRight(szN, szM, szN);
	moveLeft(szN, szM, 0);
}

void checkA() {
	int A;
	for (int i = 0; i < R; i++) {
		cin >> A;

		if(A == 1) upDownMirror();
		else if(A == 2) sideMirror();
		else if(A == 3) rot();
		else if(A == 4) reverseRot();
		else if(A == 5) orderFive();
		else if(A == 6) orderSix();
	}
}

void printArr() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cout << arr[i][j] << " ";
		cout << "\n";
	}
}

void solve() {
	checkA();
	printArr();
}

int main() { //배열 돌리기 3
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}