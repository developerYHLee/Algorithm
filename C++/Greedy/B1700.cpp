#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
	int x, p;

	Node(int x, int p) : x(x), p(p) {}

	bool operator<(const Node& o) const {
		return p > o.p;
	}
};

const int MAX = 101;
int N, K, arr[101], P[101], res;
bool outlet[101];
priority_queue<Node> PQ;

void input() {
	cin >> N >> K;
	for (int i = 1; i <= K; i++) cin >> arr[i];
	fill_n(P, K + 1, MAX);
}

void iniP() {
	for (int i = 1; i <= K; i++) {
		int k = arr[i];

		if (P[k] != MAX) continue;
		P[k] = i;
	
		PQ.push(Node(k, P[k]));
	}
}

void setP(int p) {
	int k = arr[p];

	for (int i = p + 1; i <= K; i++) {
		if (k != arr[i]) continue;

		P[k] = i;
		PQ.push(Node(k, P[k]));
		return;
	}

	P[k] = MAX;
}

void iniOutlet() {
	int tempN = 0;
	while (!PQ.empty() && tempN < N) {
		Node node = PQ.top();
		PQ.pop();

		int x = node.x, p = node.p;

		setP(p);
		
		if (outlet[x]) continue;
		outlet[x] = true;

		tempN++;
	}
}

int unplug() {
	int ret = 0, temp = 0;

	for (int i = 1; i <= K; i++) {
		if (outlet[i] && P[i] > temp) {
			temp = P[i];
			ret = i;
		}
	}

	return ret;
}

void solve() {
	iniP(); 
	iniOutlet();

	while (!PQ.empty()) {
		Node node = PQ.top();
		PQ.pop();

		int x = node.x, p = node.p;

		setP(p);

		if (outlet[x]) continue;
		
		outlet[unplug()] = false;
		outlet[x] = true;

		res++;
	}

	cout << res;
}

int main() { //멀티탭 스케줄링
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}