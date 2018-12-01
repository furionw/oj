// Copyright 2016 Qi Wang
// Date: 2016-12-25
class Solution {
 public:
  int wordsTyping(vector<string>& sentence, int rows, int cols) {
    size_t maxLen = 0;
    for (auto& word: sentence) maxLen = max(maxLen, word.size());
    if (maxLen > static_cast<size_t>(cols)) return 0;
    // startIdx -> <row, remain>
    pair<int, int> dp[cols];
    memset(dp, -1, sizeof dp);
    int res = 0;
    for (int pos = 0, rCnt = 0; ;) {
      if (pos == 0 && rCnt) {
        int times = rows / rCnt;
        res *= times;
        rCnt *= times;
      }
      if (dp[pos].first == -1) updateMap(dp, pos, sentence, cols);
      auto cost = dp[pos];
      if (rCnt + cost.first >= rows) break;
      ++res;
      rCnt += cost.first;
      pos = cost.second;
      if (pos >= cols) {
        ++rCnt;
        pos = 0;
      }
    }
    return res;
  }

 private:
  void updateMap(pair<int, int> dp[], int pos,
      const vector<string>& sentence, int cols) const {
    int curPos = pos;
    int rCnt = 0;
    for (const string& word : sentence) {
      if (curPos + word.size() <= cols) {
        curPos += word.size() + 1;
      } else {
        ++rCnt;
        curPos = word.size() + 1;
      }
    }
    dp[pos] = make_pair(rCnt, curPos);
  }
};
