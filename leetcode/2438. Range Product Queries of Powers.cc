// Date: 2022-10-19
// Method 2
// Refer to: https://leetcode.com/problems/range-product-queries-of-powers/discuss/2706327/C%2B%2B-oror-Very-simple-and-Easy-to-Understand-Solution
class Solution {
 public:
  vector<int> productQueries(int n, vector<vector<int>>& queries) {
    vector<int> powers;
    for (int i = 0; i < 31; ++i) {
      if (n & (1 << i)) {
        powers.push_back(1 << i);
      }
    }
    vector<int> answers;
    for (const auto& q : queries) {
      size_t p = powers[q[0]];
      for (size_t i = q[0] + 1; i <= q[1]; ++i) {
        p = p * powers[i] % int(1e9 + 7);
      }
      answers.push_back(p);
    }
    return answers;
  }
};

// Method 1
class Solution {
 public:
  vector<int> productQueries(int n, vector<vector<int>>& queries) {
    vector<int> powers;
    foo(n, int(log2(n)), powers);
    sort(powers.begin(), powers.end());

    vector<vector<size_t>> products(
        powers.size(),
        vector<size_t>(powers.size(), 1));
    for (size_t i = 0; i < powers.size(); ++i) {
      products[i][i] = powers[i];
      for (size_t j = i + 1; j < powers.size(); ++j) {
        products[i][j] = (products[i][j - 1] * powers[j]) % int(1e9 + 7);
      }
    }

    vector<int> answers;
    for (const auto& query : queries) {
      answers.push_back(products[query[0]][query[1]]);
    }
    return answers;
  }

 private:
  bool foo(int n, int p, vector<int>& powers) {
    int power = 1 << p;
    powers.push_back(power);
    int remain = n - power;
    if (remain == 0) {
      return true;
    } else {
      if (foo(remain, int(log2(remain)), powers)) {
        return true;
      } else {
        powers.pop_back();        
      }
    }
    if (p > 0) {
      return foo(n, p - 1, powers);
    }
    return false;
  }
};