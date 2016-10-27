#include <iostream>
#include <string>
#include <initializer_list>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

// contain then exclude itself
vector<set<int>> exclude
{
	{4},
	{1, 2, 4, 5, 7},
	{2, 6},
	{2, 5},
	{1, 5, 7},
	{3, 5},
	{3},
	{2, 4, 5, 7},
	{},
	{5}
};


int gao(const vector<set<int>>& digits, size_t idx, int sum, int N)
{	
	if (idx >= digits.size())
	{
		return sum < N? 1: 0;
	}

	int cnt = 0;
	for (int digit: digits[idx])
	{	
		int cur = sum + digit * pow(10, digits.size()-1-idx);
		if (cur <= N)
		{
			cnt += gao(digits, idx+1, cur, N);
		}
	}

	return cnt;
}

int gao()
{
	int K, N;
	cin >> K >> N;
	cin.get();
	vector<set<int>> digits(K,  {0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
	
	for (int i = 0; i < K; ++ i) 
	{
		string str;
		getline(cin, str);
		for (char c: str)
		{
			if (c == ' ')
			{
				continue;
			}
			for (size_t num = 0; num <= 9; ++ num)
			{
				if (exclude[num].count(c - '0') == 1)
				{
					digits[i].erase(num);
				}
			}
		}
	}

	return gao(digits, 0, 0, N);
}


int main() 
{
	int S;
	cin >> S;
	while (S-- != 0) 
	{
		cout << gao() << '\n';
	}
}