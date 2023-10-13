#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int main() { //»öÄ¥ 1
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll W, H, F, C, x1, y1, x2, y2;
	cin >> W >> H >> F >> C >> x1 >> y1 >> x2 >> y2;

	F = min(F, W - F);
	ll box_x = W - F, box_y = H / (C + 1), color_y = y2 - y1;

	ll color_A = 0, color_B = 0;
	if (F >= x2) color_A = (x2 - x1) * color_y;
	else if (F <= x1) color_B = (x2 - x1) * color_y;
	else {
		color_A = (F - x1) * color_y;
		color_B = (x2 - F) * color_y;
	}
	
	ll A_size = F * box_y - color_A;
	ll B_size = (box_x - F) * box_y - color_B;

	cout << (2 * (C + 1) * A_size + (C + 1) * B_size);
}