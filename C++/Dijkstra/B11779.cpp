#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<stack>

//INT_MAX 사용하기 위한 라이브러리
// #include<climits>

using namespace std;

struct Node {
public:
	int _node, _dis, _prev;

	Node(int node, int dis, int prev) : _node(node), _dis(dis), _prev(prev) {}
};

struct comp {
	bool operator()(Node o1, Node o2){
		return o1._dis > o2._dis;
	}
};

vector<Node> _bus[1001];
bool _vis[1001];
int _distance[1001];
priority_queue<Node, vector<Node>, comp> _PQ;
stack<pair<int, int>> S;

int dijkstra(int end) {
	while (!_PQ.empty()) {
		Node cur = _PQ.top();
		_PQ.pop();

		int node = cur._node, prev = cur._prev;
		if (node == end) return prev;
		if (_vis[node]) continue;
		_vis[node] = true;
		
		bool check = false;
		for (const Node& next : _bus[node]) {
			int n = next._node, d = next._dis;
			
			if (_distance[n] >= _distance[node] + d) {
				_distance[n] = _distance[node] + d;
				_PQ.push(Node(n, _distance[n], node));
				check = true;
			}
		}

		if (check) S.push(make_pair(node, prev));
	}

	return -1;
}

int main() { //최소비용 구하기 2
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int s, e, d;

		cin >> s >> e >> d;
		_bus[s].push_back(Node(e, d, 0));
	}

	int start, end;
	cin >> start >> end;
	
	//fill(_distance, _distance + N + 1, INT_MAX);
	fill(_distance, _distance + N + 1, (int)1e9);
	_distance[start] = 0;
	_PQ.push(Node(start, 0, start));
	int prev = dijkstra(end);
	
	int count = 1;
	vector<int> path;
	path.push_back(end);
	while (!S.empty()) {
		while (S.top().first != prev) S.pop();
		
		pair<int, int> cur = S.top();
		S.pop();
			
		int node = cur.first;
		path.push_back(node);
		count++;

		prev = cur.second;
	}

	cout << _distance[end] << "\n" << count << "\n";
	for (int i = size(path) - 1; i >= 0; i--) cout << path[i] << " ";

	return 0;
}