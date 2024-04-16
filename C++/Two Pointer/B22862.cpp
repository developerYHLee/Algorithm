#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Node {
	int cnt, k;

	Node(int cnt, int k) : cnt(cnt), k(k) {}
};

int N, K, arr[1000000], index;
vector<Node> info;

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];
}

void setIndex() {
	for (int i = 0; i < N; i++) {
		if (arr[i] % 2 == 0) {
			index = i;
			break;
		}
	}
}

void setInfo() {
	setIndex();

	int cnt = 0, k = 0;
	for (int i = index; i < N; i++) {
		if (arr[i] % 2 == 0) cnt++;
		else {
			if (cnt > 0) {
				info.push_back(Node(cnt, k));
				cnt = 0;
			}
			k++;
		}
	}
	if (cnt > 0) info.push_back(Node(cnt, k));
}

void solve() {
	setInfo();

	if (info.size() == 0) {
		cout << 0;
		return;
	}

	int s = 0, e = 1, temp = info[0].cnt, res = temp;
	while (e < info.size()) {
		Node sNode = info[s], eNode = info[e];
		int sCnt = sNode.cnt, sK = sNode.k, eCnt = eNode.cnt, eK = eNode.k;

		if (eK - sK <= K) {
			e++;
			temp += eCnt;
			res = max(res, temp);
		}
		else {
			s++;
			temp -= sCnt;
		}
	}

	cout << res;
}

int main() { //가장 긴 짝수 연속한 부분 수열 (large)
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}