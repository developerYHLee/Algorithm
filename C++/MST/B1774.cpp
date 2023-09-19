#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef pair<double, pair<int, int>> pdp;

vector<pdp> sorted_map;
int parent[1001];

int find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = find(parent[x]);
}

bool merge(int x, int y) {
	int a = find(x);
	int b = find(y);

	if (a == b) return false;
	
	if (a > b) parent[a] = b;
	else parent[b] = a;

	return true;
}

int main() { //우주신과의 교감
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<pair<int, int>> map;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		map.push_back({ x, y });
		parent[i] = i;
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			double dis = sqrt(pow(map[i].first - map[j].first, 2) + pow(map[i].second - map[j].second, 2));

			sorted_map.push_back({ dis,{i, j} });
		}
	}

	sort(sorted_map.begin(), sorted_map.end());
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;

		merge(x - 1, y - 1);
	}

	double sum = 0.0;
	for (int i = 0; i < sorted_map.size(); i++) {
		pdp node = sorted_map[i];
		
		if (merge(node.second.first, node.second.second)) sum += node.first;
	}

	cout << fixed;
	cout.precision(2);
	cout << round(sum * 100) / 100;
}