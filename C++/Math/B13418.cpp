#include <iostream>
#include <memory.h>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

typedef tuple<int, int, int> tiii;

vector<tiii> map;
int parent[1001];

int find(int x) {
	if (parent[x] == 0) return x;
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

void mode(int N, bool big) {
	memset(parent, 0, (N + 1) * sizeof(int));

	if(big) sort(map.begin(), map.end(), [](tiii o1, tiii o2) { return get<2>(o1) < get<2>(o2); });
	else sort(map.begin(), map.end(), [](tiii o1, tiii o2) { return get<2>(o1) > get<2>(o2); });
}

void print_map() {
	cout << endl;
	for (int i = 0; i < map.size(); i++) {
		tiii node = map[i];

		cout << get<0>(node) << " " << get<1>(node) << " " << get<2>(node) << endl;
	}
	cout << endl;
}

int main() { //학교 탐방하기
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	map.resize(M + 1);
	for (int i = 0; i <= M; i++) {
		int s, e, c;
		cin >> s >> e >> c;

		map[i] = make_tuple(s, e, c);
	}

	int worst = 0;
	mode(N, true);
	//print_map();
	for (int i = 0; i < M; i++) {
		tiii node = map[i];

		if(merge(get<0>(node), get<1>(node)) && get<2>(node) == 0) worst++;
	}

	int best = 0;
	mode(N, false);
	//print_map();
	for (int i = 0; i < M; i++) {
		tiii node = map[i];

		if (merge(get<0>(node), get<1>(node)) && get<2>(node) == 0) best++;
	}

	cout << (worst * worst - best * best);
}