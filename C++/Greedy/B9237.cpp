#include <iostream>
#include <algorithm>

using namespace std;

int tree[100000];
int main() { //ÀÌÀå´Ô ÃÊ´ë
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) cin >> tree[i];
	sort(tree, tree + N, greater<int>());

	int temp = 0, res = 0;
	for (int i = 0; i < N; i++) {
		temp--;
		res++;

		if (temp < tree[i]) temp = tree[i];
	}

	cout << res + temp + 1;
}