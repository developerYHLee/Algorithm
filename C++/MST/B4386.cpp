#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<vector<pair<double, pair<int, int>>>> map;
int parent[101];
bool check;

int find(int x) {
	if (parent[x] < 0) return x;
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	int x = find(a);
	int y = find(b);

	check = false;
	if (x == y) return;
	check = true;

	if (x > y) parent[x] = y;
	else parent[y] = x;
}

int main() { //별자리 만들기
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	double star[101][2];
	for (int i = 0; i < N; i++) {
		double x, y;
		cin >> x >> y;

		star[i][0] = x;
		star[i][1] = y;
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			double x = star[i][0] - star[j][0], y = star[i][1] - star[j][1];
			double dis = sqrt(pow(x, 2) + pow(y, 2));
			
			vector<pair<double, pair<int, int>>> node;
			node.push_back({ dis, {i, j} });
			map.push_back(node);
		}
	}
	sort(map.begin(), map.end());
	fill_n(parent, N, -1);

	double sum = 0.0;
	for (int i = 0; i < map.size(); i++) {
		for (const pair<double, pair<int, int>>& node : map[i]) {
			double d = node.first;
			int x = node.second.first, y = node.second.second;

			merge(x, y);
			if (check) sum += d;
		}
	}
	
	cout << sum;
}