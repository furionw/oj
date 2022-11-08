// Date: 2022-11-07
class StockSpanner {
 public:
  StockSpanner() {}
    
  int next(int price) {
    prices_.push_back(price);
    for (; !s_.empty() && price >= prices_[s_.top()]; s_.pop()) {}
    size_t curIdx = prices_.size() - 1;
    if (s_.empty()) {
      s_.push(curIdx);
      return curIdx + 1;
    } else {
      int res = curIdx - s_.top();
      s_.push(curIdx);
      return res;
    }
  }

 private:
  vector<int> prices_;
  stack<int> s_;
};
