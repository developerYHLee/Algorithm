#include <iostream>
#include <cmath>

using namespace std;

int main() { //¾Þ±×¸® Ã¢¿µ
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, W, H;
	cin >> N >> W >> H;

	for (int i = 0; i < N; i++) {
		int l;
		cin >> l;
		
		if (pow(l, 2) <= pow(W, 2) + pow(H, 2)) cout << "DA\n";
		else cout << "NE\n";
	}
}