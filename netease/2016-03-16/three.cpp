#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <numeric>

using namespace std;

struct Vertex {
	int value;
	bool left;
	Vertex(int v, bool l): value(v), left(l) {}
	bool operator< (const Vertex& v) const {
		return value != v.value? value > v.value: ! left;
	}
};

int gao(unordered_map<int, priority_queue<Vertex>>& m) {
	int cnt = 0;

	for (auto& kv: m) {
		auto& vertices = kv.second;
		int left_cnt = 0;
		while (! vertices.empty()) {
			auto vertex = vertices.top();
			vertices.pop();
			if (vertex.left)
				++ left_cnt;
			else 
				cnt += (--left_cnt == 0? 1: 0);
		}
	}

	return cnt;
}

int gao() {
	vector<unordered_map<int, priority_queue<Vertex>>> table(4);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++ i) {
		int x0, y0, x1, y1;
		cin >> x0 >> y0 >> x1 >> y1;
		if (y0 == y1) {
			table[0][y0].emplace(x0, x0<x1);
			table[0][y0].emplace(x1, x1<x0);
		} else if (x0 == x1) {
			table[1][x0].emplace(y0, y0<y1);
			table[1][x0].emplace(y1, y1<y0);
		} else if (x0-x1 == y0-y1) {
			table[2][x0-y0].emplace(x0, x0<x1);
			table[2][x0-y0].emplace(x1, x1<x0);
		} else { // if (x0-x1 == -(y0-y1)) 
			table[3][x0+y0].emplace(x0, x0<x1);
			table[3][x0+y0].emplace(x1, x1<x0);
		}
	}

	return accumulate(table.begin(), table.end(), 0, 
		[](int sum, unordered_map<int, priority_queue<Vertex>>& m) {
			return sum + gao(m);
		});
}

int main() {
	int S;
	cin >> S;
	while (S-- != 0) {
		cout << gao() << '\n';
	}
}
