#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
typedef pair<double, double> pdd;

pdd points[10001];

inline double get_area(pdd l1, pdd l2, pdd l3) {
	double x1 = l1.first, x2 = l2.first, x3 = l3.first;
	double y1 = l1.second, y2 = l2.second, y3 = l3.second;

	return ((x1 * y2 + x2 * y3 + x3 * y1) - (x1 * y3 + x3 * y2 + x2 * y1)) / 2;
}

int main() { //다각형의 면적
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		double x, y;
		cin >> x >> y;

		points[i] = { x, y };
	}

	double res = 0;
	for (int i = 2; i < N; i++) res += get_area(points[0], points[i - 1], points[i]);

	cout << fixed;
	cout.precision(1);
	cout << abs(res);
}