#include <stdio.h>
#include <unordered_map>
#include <algorithm>
#include <vector>

using std::unordered_map;
using std::vector;
using std::sort;

struct Vertex {
	int value;
	bool left;
	Vertex(int v, bool l) : value(v), left(l) {}
};

bool comp(const Vertex &lhs, const Vertex &rhs) {
	if (lhs.value < rhs.value) {
		return true;
	} else if (lhs.value > rhs.value) {
		return false;
	} else {
		return lhs.left;
	}
}

int help(vector<Vertex> vertices) {
	sort(vertices.begin(), vertices.end(), comp);
	int count = 0, ret = 0;
	for (auto &v : vertices) {
		if (v.left) {
			count++;
		} else {
			count--;
			if (count == 0)
				ret++;
		}
	}
	return ret;
}

void test() {
	int N;
	scanf("%d", &N);
	vector<unordered_map<int, vector<Vertex>>> table(4);
	for (int i = 0; i < N; i++) {
		int x0, y0, x1, y1;
		scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
		if (y0 == y1) {
			if (x0 < x1) {
				table[0][y0].emplace_back(x0, true);
				table[0][y0].emplace_back(x1, false);
			} else {
				table[0][y0].emplace_back(x0, false);
				table[0][y0].emplace_back(x1, true);
			}
		} else if (x0 == x1) {
			if (y0 < x1) {
				table[1][x0].emplace_back(y0, true);
				table[1][x0].emplace_back(y1, false);
			} else {
				table[1][x0].emplace_back(y0, false);
				table[1][x0].emplace_back(y1, true);
			}
		} else if ((x1 - x0) * (y1 - y0) > 0) {
			int b = y0 - x0;
			if (x0 < x1) {
				table[2][b].emplace_back(x0, true);
				table[2][b].emplace_back(x1, false);
			} else {
				table[2][b].emplace_back(x0, false);
				table[2][b].emplace_back(x1, true);
			}
		} else {
			int b = x0 + y0;
			if (x0 < x1) {
				table[3][b].emplace_back(x0, true);
				table[3][b].emplace_back(x1, false);
			} else {
				table[3][b].emplace_back(x0, false);
				table[3][b].emplace_back(x1, true);
			}
		}
	}
	int count = 0;
	for (auto &i : table) {
		for (auto &j : i) {
			count += help(j.second);
		}
	}
	printf("%d\n", count);
}

int main() {
	int S;
	scanf("%d", &S);
	for (int i = 0; i < S; i++)
		test();
	return 0;
}
