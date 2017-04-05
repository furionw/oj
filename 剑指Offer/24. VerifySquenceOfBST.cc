// Copyright 2017 Qi Wang
// Date: 2017-04-03
class Solution {
 public:
  bool VerifySquenceOfBST(vector<int> sequence) {
    if (sequence.size() <= 1) return sequence.size() == 1;
    int root = sequence.back();
    int pivot = sequence.size() - 2;
    for (; pivot >= 0 && sequence[pivot] > root; --pivot) {}
    bool result = true;
    if (pivot < sequence.size() - 2)
      result = VerifySquenceOfBST(vector<int>(sequence.begin() + pivot + 1,
          --sequence.end()));
    auto less = [root](int elem) { return elem < root; };
    if (result && pivot >= 0)
      result = all_of(sequence.begin(), sequence.begin() + pivot + 1, less)
          && VerifySquenceOfBST(vector<int>(sequence.begin(),
              sequence.begin() + pivot + 1));
    return result;
  }
};
