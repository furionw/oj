// Copyright 2016 Qi Wang
// Date: 2016-12-29
class Vector2D {
 public:
  Vector2D(vector<vector<int>>& vec2d)
      : vec2d_(move(vec2d)), rowIt_(vec2d_.begin()) {
    if (rowIt_ != vec2d_.end()) colIt_ = rowIt_->begin();
  }

  int next() {
    return *(colIt_++);
  }

  bool hasNext() {
    // Note that when input is empty [[]], colIt_ won't be initialized,
    // which might cause undefined behavior
    while (rowIt_ != vec2d_.end() && colIt_ == rowIt_->end())
      colIt_ = (++rowIt_)->begin();
    return rowIt_ != vec2d_.end();
  }

 private:
  vector<vector<int>> vec2d_;
  vector<vector<int>>::const_iterator rowIt_;
  vector<int>::const_iterator colIt_;
};
