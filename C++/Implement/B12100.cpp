#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
typedef vector<vector<int>> vvi;
void move(int, vvi);

int MAX = 0, N;

void print_map(int cnt, vvi temp_map) {
	cout << "cnt : " << cnt << '\n';
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cout << temp_map[i][j] << " ";
		cout << '\n';
	}
	cout << '\n';
}

void check(vvi temp_map) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) MAX = max(MAX, temp_map[i][j]);
	}
}

void move_right(int cnt, vvi temp_map) {
	for (int i = 1; i <= N; i++) {
		int l = N - 1, r = N, p = N;

		while (l > 0) {
			int num_l = temp_map[i][l], num_r = temp_map[i][r];

			if (num_l == 0 || num_r == 0) {
				if (num_r == 0) r--;
				l--;

				continue;
			}

			if (num_l == num_r) {
				temp_map[i][p] = num_l + num_r;
				r = l - 1;
				l -= 2;
			}
			else {
				temp_map[i][p] = num_r;
				r = l;
				l--;
			}
			p--;
		}

		temp_map[i][p] = temp_map[i][r];
		p--;

		for (int j = p; j > 0; j--) temp_map[i][j] = 0;
	}

	move(cnt, temp_map);
}

void move_left(int cnt, vvi temp_map) {
	for (int i = 1; i <= N; i++) {
		int l = 1, r = 2, p = 1;

		while (r <= N) {
			int num_l = temp_map[i][l], num_r = temp_map[i][r];

			if (num_l == 0 || num_r == 0) {
				if (num_l == 0) l++;
				r++;

				continue;
			}

			if (num_l == num_r) {
				temp_map[i][p] = num_l + num_r;
				l = r + 1;
				r += 2;
			}
			else {
				temp_map[i][p] = num_l;
				l = r;
				r++;
			}
			p++;
		}

		temp_map[i][p] = temp_map[i][l];
		p++;

		for (int j = p; j <= N; j++) temp_map[i][j] = 0;
	}

	move(cnt, temp_map);
}

void move_up(int cnt, vvi temp_map) {
	for (int i = 1; i <= N; i++) {
		int u = 1, d = 2, p = 1;

		while (d <= N) {
			int num_u = temp_map[u][i], num_d = temp_map[d][i];

			if (num_u == 0 || num_d == 0) {
				if (num_u == 0) u++;
				d++;

				continue;
			}

			if (num_u == num_d) {
				temp_map[p][i] = num_u + num_d;
				u = d + 1;
				d += 2;
			}
			else {
				temp_map[p][i] = num_u;
				u = d;
				d++;
			}
			p++;
		}

		temp_map[p][i] = temp_map[u][i];
		p++;

		for (int j = p; j <= N; j++) temp_map[j][i] = 0;
	}

	move(cnt, temp_map);
}

void move_down(int cnt, vvi temp_map) {
	for (int i = 1; i <= N; i++) {
		int u = N - 1, d = N, p = N;

		while (u > 0) {
			int num_u = temp_map[u][i], num_d = temp_map[d][i];

			if (num_u == 0 || num_d == 0) {
				if (num_d == 0) d--;
				u--;

				continue;
			}

			if (num_u == num_d) {
				temp_map[p][i] = num_u + num_d;
				d = u - 1;
				u -= 2;
			}
			else {
				temp_map[p][i] = num_d;
				d = u;
				u--;
			}
			p--;
		}

		temp_map[p][i] = temp_map[d][i];
		p--;

		for (int j = p; j > 0; j--) temp_map[j][i] = 0;
	}

	move(cnt, temp_map);
}

void move(int cnt, vvi temp_map) {
	if (cnt == 5) {
		check(temp_map);
		//print_map(cnt, temp_map);

		return;
	}

	move_right(cnt + 1, temp_map);
	move_left(cnt + 1, temp_map);
	move_up(cnt + 1, temp_map);
	move_down(cnt + 1, temp_map);
}

int main() { //2048 (Easy)
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	vvi map(N + 2, vector<int>(N + 2));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cin >> map[i][j];
	}

	move(0, map);
	cout << MAX;
}