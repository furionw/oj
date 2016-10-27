#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

// first: ans_num, second: right ones among answers
// sorted by first -- less<int>
vector<pair<int, int>> get_solutions(int require, int max_chances, int S, int T) {
	vector<pair<int, int>> res;
	for (int wrong = 0; 
		wrong <= max_chances && (wrong-1) * T < require; ++ wrong) {
		int right = ceil((require - wrong * T) * 1.0 / S);
		if (wrong + right > max_chances)
			break;
		res.emplace_back(make_pair(wrong+right, right));
	}
	return res;
}

void gao() {
	// input
	int N, M, S, T;
	cin >> N >> M >> S >> T;
	const int NO = M + 1;
	vector<int> A;
	for (int i = 0; i < N; ++ i) {
		int a;
		cin >> a;
		A.push_back(a);
	}

	// right[i][j]
	// i: i# stage ("guan" in Chinese)
	// j: # of chance has been used
	// value: # of right answer in j answers
	vector<vector<int>> rights(N+1, vector<int>(M+1, NO));
	// dp init
	rights[0][0] = 0;
	for (int i = 0; i <= N-1; ++ i) {
		int chance_used = NO;
		for (int j = 0; j <= M; ++ j)
			if (rights[i][j] != NO) {
				chance_used = j;
				break;
			}
		if (chance_used == NO) {
			cout << "No\n";
			return;
		}
		auto solutions = get_solutions(A[i], M - chance_used, S, T);
		for (int j = chance_used; j <= M && rights[i][j] != NO; ++ j)
			for (auto solution: solutions) 
				if (j + solution.first <= M)
					rights[i+1][j+solution.first] = 
						min(rights[i+1][j+solution.first], rights[i][j] + solution.second);
				else 
					break;
	}

	int min_right = *min_element(rights[N].begin(), rights[N].end());
	if (min_right != NO)
		cout << min_right << '\n';
	else
		cout << "No\n";
}

int main() {
	int Q;
	cin >> Q;
	while (Q-- != 0) {
		gao();
	}
}
