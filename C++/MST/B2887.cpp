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

int main() { //�༺ �ͳ�
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	//0 : {x ��ǥ, ��ȣ}, 1 : {y ��ǥ, ��ȣ}, 2 : {z ��ǥ, ��ȣ}
	vector<pair<int, int>> map[3];
	for (int i = 0; i < N; i++) {
		int x, y, z;
		cin >> x >> y >> z;
 
		map[0].push_back({ x, i });
		map[1].push_back({ y, i });
		map[2].push_back({ z, i });
	}

	//x, y, z ���� ����
	sort(map[0].begin(), map[0].end());
	sort(map[1].begin(), map[1].end());
	sort(map[2].begin(), map[2].end());
	
	//����� �� ��带 x, y, z���� �Ÿ� ���
	//{�Ÿ� ����, ��ȣ1, ��ȣ2}
	vector<vector<int>> sorted_map[3];
	for (int i = 0; i < 3; i++) {
		for (int j = 1; j < N; j++) {
			int dis = abs(map[i][j - 1].first - map[i][j].first);
			int s = map[i][j - 1].second, e = map[i][j].second;

			vector<int> node = { dis, s, e };
			sorted_map[i].push_back(node);
		}
	}

	//�Ÿ� ��� �� ������
	sort(sorted_map[0].begin(), sorted_map[0].end());
	sort(sorted_map[1].begin(), sorted_map[1].end());
	sort(sorted_map[2].begin(), sorted_map[2].end());
	
	fill_n(parent, N, -1);

	long long sum = 0;
	int index[3]{};
	while (true) {
		for (int i = 0; i < 3; i++) {
			//x, y, z map �߿� �� ���� ��� Ž���ϸ� ����
			if (index[i] == N - 1) {
				cout << sum;
				return 0;
			}
		}

		//x, y, z �߿� �Ÿ��� ���� ���� ��ǥ ����
		int MIN = 1e9 * 2 + 1, index_MIN = 0;
		for (int i = 0; i < 3; i++) {
			vector<int> node = sorted_map[i][index[i]];

			if (MIN > node[0]) {
				MIN = node[0];
				index_MIN = i;
			}
		}
		
		//�Ÿ��� ���� ���� ����� �� �� �˻� �� �̹� �˻��� ���� �ƴ϶�� sum�� ����
		vector<int> node = sorted_map[index_MIN][index[index_MIN]];
		if (merge(node[1], node[2])) sum += MIN;

		//�˻��� map �ε��� + 1
		index[index_MIN]++;
	}
}