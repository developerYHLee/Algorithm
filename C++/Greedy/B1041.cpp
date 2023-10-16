#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int two[1000001];
int num[6];
bool vis[6];
int a = 150, b = 150, c = 150;

bool check(int x, int y) {
	if (x > y) swap(x, y);

	if (x == 0 && y == 5) return false;
	if (x == 1 && y == 4) return false;
	if (x == 2 && y == 3) return false;

	return true;
}

int cal(int count, int temp) {
	if (count == 3) return temp;

	for (int i = 0; i < 6; i++) {
		if (vis[i]) continue;
		
		bool ch = true;
		for (int j = 0; j < 6; j++) {
			if (ch && vis[j]) ch = check(i, j);
		}
		if (!ch) continue;

		vis[i] = true;
		int res = cal(count + 1, temp + num[i]);
		vis[i] = false;
		
		if (count == 1) b = min(b, res);
		else if (count == 2) c = min(c, res);
	}

	return temp;
}

int main() { //ÁÖ»çÀ§
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	
	for (int i = 0; i < 6; i++) {
		cin >> num[i];
		a = min(a, num[i]);
	}

	for (int i = 0; i < 6; i++) {
		vis[i] = true;
		a = min(a, cal(1, num[i]));
		vis[i] = false;
	}

	if (N == 1) {
		int temp = 0;
		for (int i = 0; i < 6; i++) {
			temp += num[i];
			a = max(num[i], a);
		}
		temp -= a;
		cout << temp;

		return 0;
	}

	two[2] = 4;
	for (int i = 3; i <= N; i++) two[i] = two[i - 1] + 8;

	cout << ((5 * (ll)N * N - 16 * (ll)N + 12) * a + (ll)two[N] * b + (ll)4 * c);
}