#include <iostream>
#include <deque>

using namespace std;

struct Node {
	int x, index;

	Node(int x, int index) : x(x), index(index) {}
};

int N, L, arr[5'000'000];
deque<Node> D;

void input() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) cin >> arr[i];
}

void printRes(int index) {
	D.push_back({ arr[index], index });
	cout << D.front().x << " ";
}

void solve() {
	printRes(0);
	for (int i = 1; i < N; i++) {
		if (D.front().index == i - L) D.pop_front();

		while (!D.empty() && D.back().x > arr[i]) D.pop_back();
		
		printRes(i);
	}
}

int main() { //ÃÖ¼Ú°ª Ã£±â
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}