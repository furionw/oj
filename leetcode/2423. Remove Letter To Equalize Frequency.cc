// Date: 2022-10-07
class Solution {
 public:
  bool equalFrequency(string word) {
    unordered_map<char, int> freqByChar;
    for (char c : word) {
      ++freqByChar[c];
    }
    // pass "zz"
    if (freqByChar.size() == 1) {
      return true;
    }

    map<int, int> cntByfreq;
    for (const auto& [_, freq] : freqByChar) {
      ++cntByfreq[freq];
    }
    // "abbccc"
    if (cntByfreq.size() > 2) {
      return false;
    } else if (cntByfreq.size() == 1) {
      // pass "abc"
      // fail "aabbcc"
      return cntByfreq.begin()->first == 1;
    }

    // There are two frequencies at this point
    const auto& [freq1, cnt1] = *cntByfreq.begin();
    const auto& [freq2, cnt2] = *++cntByfreq.begin();
    // pass "cccd"
    if (freq1 == 1 && cnt1 == 1) {
      return true;
    }
    if (freq1 + 1 != freq2) {
      return false;
    }
    return cnt2 == 1;
  }
};
