// 2020-07-16
class Solution {
  public int trap(int[] height) {
    int result = 0;
    Stack<Integer> decreasingStk = new Stack<Integer>();
    for (int i = 0; i < height.length; ++i) {
      if (decreasingStk.empty() || height[i] < height[decreasingStk.peek()]) {
        decreasingStk.push(i);
      } else {
        while (!decreasingStk.empty() && height[i] > height[decreasingStk.peek()]) {
          int last = decreasingStk.pop();
          if (decreasingStk.empty()) {
            break;
          }
          int penultimate = decreasingStk.peek();
          result += (i - penultimate - 1) *
              (Math.min(height[penultimate], height[i]) - height[last]);
        }
        decreasingStk.push(i);
      }
    }
    return result;
  }
}
