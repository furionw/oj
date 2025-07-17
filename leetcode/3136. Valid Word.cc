// 2025-07-16
class Solution {
 public:
  bool isValid(string word) {
    bool foundV = false;
    bool foundC = false;
    for (char c : word) {
      bool alphanumeric = ('0' <= c && c <= '9') || isChar(c);
      if (!alphanumeric) {
        return false;
      }

      foundV = foundV || vowels.contains(c);
      foundC = foundC || (isChar(c) && !vowels.contains(c));
    }
    return word.size() >= 3 && foundV && foundC;
  }

 private:
  bool isChar(char c) const {
    return ('a' <= c && c <= 'z')
        || ('A' <= c && c <= 'Z');
  }

  unordered_set<char> vowels {
    'a', 'e', 'i', 'o', 'u',
    'A', 'E', 'I', 'O', 'U'
  };
};

// 2025-07-16
class Solution {
 public:
  bool isValid(string word) {
    return word.size() >= 3
        && alphanumeric(word)
        && vowel(word)
        && consonant(word);
  }

 private:
  bool isChar(char c) {
    return ('a' <= c && c <= 'z')
        || ('A' <= c && c <= 'Z');
  }

  bool alphanumeric(const string& word) {
    return all_of(word.begin(), word.end(), [&](char c) {
      return ('0' <= c && c <= '9') || isChar(c);
    });
  }

  bool vowel(const string& word) {
    return any_of(word.begin(), word.end(), [&](char c) {
      return vowels.contains(c);
    });
  }

  bool consonant(const string& word) {
    return any_of(word.begin(), word.end(), [&](char c) {
      return isChar(c) && !vowels.contains(c);
    });
  }

  unordered_set<char> vowels {
    'a', 'e', 'i', 'o', 'u',
    'A', 'E', 'I', 'O', 'U'
  };
};
