#include <iostream>

using namespace std;

int getNum(int n) {
	int ret = 0;
	while (n > 0) {
		ret = ret * 10 + n % 10;
		n /= 10;
	}
	return ret;
}

int main() { //µÚÁýÈù µ¡¼À
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int A, B;
	cin >> A >> B;
	cout << getNum(getNum(A) + getNum(B));
}