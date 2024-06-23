#include <iostream>
#include <algorithm>

using namespace std;

struct Node {
	string name;
	int k, e, m;

	Node() {}
	Node(string name, int k, int e, int m) : name(name), k(k), e(e), m(m) {}

	bool operator<(const Node& o) const {
		if (k != o.k) return k > o.k;
		if (e != o.e) return e < o.e;
		if (m != o.m) return m > o.m;
		return name < o.name;
	}
};

int N;
Node score[100'000];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string name;
		int k, e, m;

		cin >> name >> k >> e >> m;
		score[i] = Node(name, k, e, m);
	}
}

void solve() {
	sort(score, score + N);
	for (int i = 0; i < N; i++) cout << score[i].name << "\n";
}

int main() { //±¹¿µ¼ö
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}