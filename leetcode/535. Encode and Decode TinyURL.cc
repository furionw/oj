// Copyright 2017 Qi Wang

// More effort should be put in this question.
// Think about the hints in LC 534: https://leetcode.com/problems/design-tinyurl/#/description

// Date: 2017-07-12
// Refer to: https://discuss.leetcode.com/topic/81633/easy-solution-in-java-5-line-code/6
class Solution {
 public:
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    long_urls_.push_back(longUrl);
    return to_string(long_urls_.size() - 1);
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    int idx = stoi(shortUrl);
    return idx < long_urls_.size() ? long_urls_[idx] : "";
  }

 private:
  vector<string> long_urls_;
};