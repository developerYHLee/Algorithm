#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef vector<vector<int>> vvi;

map<string, int> m_index;
set<string> king;
string name[151];
int degree[151], N, M;
vvi graph(151), parent(151, vector<int>(2));
double family[151];

int set_name(string str, int& index) {
	int ret = index;
	name[index] = str;
	m_index.insert({ str, index++ });

	return ret;
}

void input() {
	cin >> N >> M;

	int index = 0;
	string str;
	cin >> str;
	
	family[set_name(str, index)] = 1;

	for (int i = 0; i < N; i++) {
		cin >> str;

		int c_index = 0;
		auto k = m_index.find(str);
		if (k == m_index.end()) c_index = set_name(str, index);
		else c_index = k->second;

		degree[c_index] += 2;

		for (int j = 0; j < 2; j++) {
			cin >> str;

			int p_index = 0;
			auto k = m_index.find(str);
			if (k == m_index.end()) p_index = set_name(str, index);
			else p_index = k->second;

			graph[p_index].push_back(c_index);
			parent[c_index][j] = p_index;
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> str;
		king.insert(str);
	}
}

int find_king(string str) {
	auto k = m_index.find(str);
	if (k != m_index.end()) return k ->second;
	return -1;
}

void set_family(int child) {
	for (int i : parent[child]) family[child] += family[i];
	family[child] /= 2;
}

void topological_sort() {
	queue<int> Q;
	for (auto iter : m_index) {
		int index = iter.second;
		if (degree[index] == 0) Q.push(index);
	}

	while(!Q.empty()) {
		int p = Q.front();
		Q.pop();

		for (int c : graph[p]) {
			if (--degree[c] == 0) {
				Q.push(c);
				set_family(c);
			}
		}
	}
}

int main() { //¿ÕÀ§ °è½Â
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	topological_sort();

	double m = 0;
	int index = 0;
	for (auto iter : king) {
		int k = find_king(iter);
		if (k == -1) continue;

		if (m <= family[k]) {
			m = family[k];
			index = k;
		}
	}

	cout << name[index];
}