#include <cstdlib>
#include <climits>
#include <iostream>

using namespace std;

class Solution 
{
 public:
  int reverse(int x) {
    if (overflow(x))
      return 0;
    return reverseIter(0, x);
  }
 
 private:
  bool overflow(int x) {
    // The number between [-1e9, 1e9] will not cause overflow after reversion.
    if (x >= -1e9 && x <= 1e9)
      return false;
    else if (x == INT_MIN)
      return true;

    //     7463847412 ->  2147483647 
    // or -8463847412 -> -2147483648
    // Given an integer x, say its digits is like {x0, x1, ..., x9}
    // 1. The x0 must be 1 or 2, or it will return false before the program runs here
    // 2. We only have to consider the relationship between {x1, ..., x9} and 463847412, which is reverse by the lower digits of INT_MAX
    x = abs(x);
    int bound = reverseIter(0, INT_MAX / 10);
    for (int num = bound; num != 0; num /= 10, x /= 10)
      if (x % 10 > num % 10)
        return true;
      else if (x % 10 < num % 10)
        return false;

    return false;
  }

  inline int reverseIter(int res, int x) {
    if (x == 0)
      return res;
    else
      return reverseIter(res * 10 + x % 10, x / 10);
  }
};

int main() {
  cout << Solution().reverse(-2147483412) << '\n';

}

