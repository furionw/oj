// Copyright 2016 Qi Wang
// Date: 2016-12-25
class ZigzagIterator {
 public:
  ZigzagIterator(vector<int>& v1, vector<int>& v2)
      : vts_({move(v1), move(v2)}) {
    if (!hasNext(flag_)) flag_ = !flag_;
  }

  int next() {
    int res = vts_[flag_][idxs_[flag_]++];
    if (hasNext(!flag_)) flag_ = !flag_;
    return res;
  }

  bool hasNext() {
    return hasNext(flag_);
  }

 private:
  bool hasNext(bool flag) const {
    return idxs_[flag] < vts_[flag].size();
  }

  bool flag_ = 0;
  size_t idxs_[2] = {0, 0};
  vector<int> vts_[2];
};
