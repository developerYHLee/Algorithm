#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[100001];

int find(int x) {
	if (parent[x] < 0) return x;
	return parent[x] = find(parent[x]);
}

bool merge(int a, int b) {
	int x = find(a);
	int y = find(b);

	if (x == y) return false;
	if (x > y) parent[x] = y;
	else parent[y] = x;

	return true;
}

int main() { //행성 터널
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	//0 : {x 좌표, 번호}, 1 : {y 좌표, 번호}, 2 : {z 좌표, 번호}
	vector<pair<int, int>> map[3];
	for (int i = 0; i < N; i++) {
		int x, y, z;
		cin >> x >> y >> z;
 
		map[0].push_back({ x, i });
		map[1].push_back({ y, i });
		map[2].push_back({ z, i });
	}

	//x, y, z 각각 정렬
	sort(map[0].begin(), map[0].end());
	sort(map[1].begin(), map[1].end());
	sort(map[2].begin(), map[2].end());
	
	//가까운 두 노드를 x, y, z끼리 거리 계산
	//{거리 절댓값, 번호1, 번호2}
	vector<vector<int>> sorted_map[3];
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j < N; j++) {
			int dis = abs(map[i][j - 1].first - map[i][j].first);
			int s = map[i][j - 1].second, e = map[i][j].second;

			vector<int> node = { dis, s, e };
			sorted_map[i].push_back(node);
		}
	}

	//거리 계산 후 재정렬
	sort(sorted_map[0].begin(), sorted_map[0].end());
	sort(sorted_map[1].begin(), sorted_map[1].end());
	sort(sorted_map[2].begin(), sorted_map[2].end());
	
	fill_n(parent, N, -1);

	long long sum = 0;
	int index[3]{};
	while (true) {
		for (int i = 0; i < 3; i++) {
			//x, y, z map 중에 한 개를 모두 탐색하면 종료
			if (index[i] == N - 1) {
				cout << sum;
				return 0;
			}
		}

		//x, y, z 중에 거리가 가장 작은 좌표 저장
		int MIN = 1e9 * 2 + 1, index_MIN = 0;
		for (int i = 0; i < 3; i++) {
			vector<int> node = sorted_map[i][index[i]];

			if (MIN > node[0]) {
				MIN = node[0];
				index_MIN = i;
			}
		}
		
		//거리가 가장 작은 노드의 두 점 검사 후 이미 검사한 점이 아니라면 sum에 더함
		vector<int> node = sorted_map[index_MIN][index[index_MIN]];
		if (merge(node[1], node[2])) sum += MIN;

		//검사한 map 인덱스 + 1
		index[index_MIN]++;
	}
}