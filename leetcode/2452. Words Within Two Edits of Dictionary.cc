// Date: 2022-11-01
class Solution {
 public:
  vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
    vector<string> result;
    for (const auto& query : queries) {
      for (const auto& word : dictionary) {
        if (diff(query, word) <= 2) {
          result.push_back(query);
          break;
        }
      }
    }
    return result;
  }

 private:
  int diff(const string& query, const string& word) {
    int cnt = 0;
    for (size_t i = 0; i < query.size(); ++i) {
      cnt += query[i] != word[i];
    }
    return cnt;
  }
};
