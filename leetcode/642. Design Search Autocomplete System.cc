// Copyright 2017 Qi Wang
// Date: 2017-10-19
class AutocompleteSystem {
 public:
  AutocompleteSystem(vector<string> sentences, vector<int> times) {
    for (int i = 0; i < sentences.size(); ++i) {
      sentence_to_freq_map_[sentences[i]] = times[i];
    }
  }
  
  vector<string> input(char c) {
    if (c == '#') {
      ++sentence_to_freq_map_[input_];
      input_.clear();
      return {};
    } else {
      input_ += c;
      priority_queue<P, vector<P>, comp> pq;
      for (auto itr = sentence_to_freq_map_.lower_bound(input_);
           itr != sentence_to_freq_map_.end(); ++itr) {
        // if (itr->first.find(input_) == string::npos) break;
        if (strncmp(itr->first.data(), input_.data(), input_.size()) != 0)
          break;
        pq.emplace(itr->first, itr->second);
        if (pq.size() > 3) pq.pop();
      }
      list<string> result;
      for (; !pq.empty(); pq.pop()) {
        result.push_front(pq.top().first);
      }
      return vector<string>(result.begin(), result.end());
    }
  }

 private:
  using P = pair<string, int>;

  struct comp {
    bool operator ()(const P& lhs, const P& rhs) const {
      return lhs.second != rhs.second ? lhs.second > rhs.second
                                      : lhs.first < rhs.first;
    }
  };

  string input_;
  map<string, int> sentence_to_freq_map_;
};

// Date: 2017-08-16
using P = pair<string, int>;
struct comp {
  bool operator ()(const P& lhs, const P& rhs) {
    return lhs.second != rhs.second ? lhs.second > rhs.second
                                    : lhs.first < rhs.first;
  }
};
 
class AutocompleteSystem {
 public:
  AutocompleteSystem(vector<string> sentences, vector<int> times) {
    input_.clear();
    sentence_to_freq_map_.clear();
    for (int i = 0; i < sentences.size(); ++i) {
      sentence_to_freq_map_[sentences[i]] = times[i];
    }
  }
    
  vector<string> input(char c) {
    if (c == '#') {
      ++sentence_to_freq_map_[input_];
      input_.clear();
      return {};
    }
    input_ += c;
    priority_queue<P, vector<P>, comp> pq;
    for (const auto& p : sentence_to_freq_map_) {
      if (strncmp(p.first.data(), input_.data(), input_.size()) == 0) {
        pq.push(p);
        if (pq.size() > 3) pq.pop();
      }
    }
    vector<string> result;
    while (!pq.empty()) {
      result.push_back(move(pq.top().first));
      pq.pop();
    }
    reverse(result.begin(), result.end());
    return result;
  }
 
 private:
  string input_;
  unordered_map<string, int> sentence_to_freq_map_;
};

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