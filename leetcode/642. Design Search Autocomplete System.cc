// Copyright 2017 Qi Wang
// Date: 2017-07-18
// Refer to Fangrui Song's solution
class AutocompleteSystem {
 public:
  AutocompleteSystem(vector<string> sentences, vector<int> times) {
    for (size_t i = 0; i < sentences.size(); ++i) {
      dict_[sentences[i]] = times[i];
    }
    begin_ = dict_.begin();
    end_ = dict_.end();
  }
  
  vector<string> input(char c) {
    if ('#' == c) {
      ++dict_[str_];
      str_.clear();
      begin_ = dict_.begin();
      end_ = dict_.end();
      return {};
    } else {
      str_ += c;
      // begin
      for (; begin_ != end_ && begin_->first < str_; ++begin_) {}
      str_ += '\x7f';
      // end
      if (begin_ != end_ && dict_.end() == end_) --end_;
      for (; begin_ != end_ && end_->first > str_; --end_) {}
      if (dict_.end() != end_ && end_->first <= str_) ++end_;
      str_.pop_back();
      // intermedia result
      vector<pair<int, string>> temp;
      for (auto it = begin_; it != end_; ++it) {
        // Use minus operator here!
        temp.emplace_back(-it->second, it->first);
      }
      sort(temp.begin(), temp.end());
      // result
      vector<string> result;
      for (size_t i = 0; i < 3 && i < temp.size(); ++i) {
        result.push_back(temp[i].second);
      }
      return result;
    }
  }

 private:
  string str_;
  map<string, int> dict_;
  map<string, int>::iterator begin_, end_;
};