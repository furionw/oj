// 2025-06-04
class Solution {
 public:
  string answerString(string word, int numFriends) {
    if (numFriends == 1) {
      return word;
    }

    string result;
    
    for (int i = 0; i < word.size(); ++i) {
      // needs to take care of `max(0, numFrinds + 1 - i)` friends after this substr
      // e.g. numFrinds = 5, i = 3. There are 1 more friend.
      size_t remainingFriends = max(0, numFriends - i - 1);
      size_t substrSz = word.size() - remainingFriends - i;
      string candidate = word.substr(i, substrSz);
      result = max(candidate, result);
    }

    return result;
  }
};

// case 1: word = "word", numFriends = 1