// 2025-04-25
// 3 <= m <= 10^5
// 1 <= k*2 < m
// 1 <= num <= 10^5
class MKAverage {
 public:
  MKAverage(int m, int k): m_(m), k_(k) {}
    
  void addElement(int num) {
    stream_.push_back(num);

    if (stream_.size() < m_) {
      return;
    }

    if (stream_.size() == m_ && sm_.empty()) {
      init();
      return;
    }

    // Insert num
    if (num <= *sm_.rbegin()) {
      sm_.insert(num);
    } else if (num <= *mid_.rbegin()) {
      insertMid(num);
    } else {
      lg_.insert(num);
    }

    num = stream_.front();
    stream_.pop_front();
    if (num <= *sm_.rbegin()) {
      erase(sm_, num);
    } else if (num <= *mid_.rbegin()) {
      eraseMid(num);
    } else {
      erase(lg_, num);
    }

    if (sm_.size() < k_) {
      num = *mid_.begin();
      eraseMid(num);
      sm_.insert(num);
    } else if (sm_.size() > k_) {
      num = *sm_.rbegin();
      erase(sm_, num);
      insertMid(num);
    }

    if (mid_.size() < m_ - 2 * k_) {
      num = *lg_.begin();
      erase(lg_, num);
      insertMid(num);
    } else if (mid_.size() > m_ - 2 * k_) {
      num = *mid_.rbegin();
      eraseMid(num);
      lg_.insert(num);
    }

    // inspect();
  }
    
  int calculateMKAverage() {
    if (mid_.empty()) {
      return -1;
    }
    // inspect();
    return sum_ / mid_.size();
  }
  
 private:
  void erase(multiset<int>& nums, int num) {
    auto it = nums.find(num);
    nums.erase(it);
  }

  void eraseMid(int num) {
    erase(mid_, num);
    sum_ -= num;
  }

  void insertMid(int num) {
    mid_.insert(num);
    sum_ += num;
  }

  void init() {
    multiset<int> s;
    for (int num : stream_) {
      s.insert(num);
    }
    auto it = s.begin();
    for (; sm_.size() < k_; ++it) {
      sm_.insert(*it);
    }
    for (; mid_.size() < m_ - 2 * k_; ++it) {
      insertMid(*it);
    }
    for (; it != s.end(); ++it) {
      lg_.insert(*it);
    }
  }

  void inspect() {
    cout << "sm = ";
    for (int num : sm_) {
      cout << num << ", ";
    }
    cout << endl;

    cout << "mid = ";
    for (int num : mid_) {
      cout << num << ", ";
    }
    cout << endl;

    cout << "lg = ";
    for (int num : lg_) {
      cout << num << ", ";
    }
    cout << endl << endl;
  }

  multiset<int> sm_;
  multiset<int> mid_;
  multiset<int> lg_;
  int m_;
  int k_;
  int64_t sum_ = 0;
  list<int> stream_;
};
