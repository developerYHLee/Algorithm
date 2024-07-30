#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;
typedef long long ll;

struct Node {
	ll num;
	string str;

	Node(ll num, string str) : num(num), str(str) {}
};

ll A, B;

void input() {
	cin >> A >> B;
}

void solve() {
	if (A == B) {
		cout << 0;
		return;
	}

	queue<Node> Q;
	unordered_set<ll> vis;

	Q.push(Node(A * A, "*"));
	vis.insert(A * A);
	Q.push(Node(A + A, "+"));
	vis.insert(A + A);
	Q.push(Node(0, "-"));
	vis.insert(0);
	Q.push(Node(1, "/"));
	vis.insert(1);

	while (!Q.empty()) {
		Node node = Q.front();
		Q.pop();

		ll num = node.num;
		string str = node.str;

		if (num == B) {
			if (str.size() == 0) cout << 0;
			else cout << str;

			return;
		}

		ll temp = num * num;

		if (temp <= B && vis.find(temp) == vis.end()) {
			vis.insert(temp);
			Q.push(Node(temp, str + "*"));
		}

		temp = num + num;

		if (temp <= B && vis.find(temp) == vis.end()) {
			vis.insert(temp);
			Q.push(Node(temp, str + "+"));
		}
	}

	cout << -1;
}

int main() { //4¿¬»ê
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
}