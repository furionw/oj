// Date: 2022-11-04
// Refer to previous solution in 2014-09
class Solution {
 public:
  int largestRectangleArea(vector<int>& height) {
    height.push_back(-1);
    stack<int> s;
    int maxx = 0;
    for (int i = 0; i < height.size();) {
      if (s.empty() || height[s.top()] <= height[i]) {
        s.push(i);
        ++i;
      } else {
        int top = s.top();
        s.pop();
        maxx = max(
            maxx,
            height[top] * (
                s.empty() ? i : (i - s.top() - 1)
            )
        );
      }
    }
    return maxx;
  }
};

// Date: 2014-09
class Solution {
 public:
  int largestRectangleArea(vector<int> &height) 
  {
    height.push_back(-1); // dummy element
    stack<int> s;
    int maxx = 0;
    for (int i = 0; i < height.size(); )
    {
      if (s.empty()==true || height[s.top()]<=height[i])
      {
        s.push(i ++); // -1 will be pushed at last, and nothing will happen
      } else 
      {
        int top_index = s.top();
        s.pop();
        maxx = max(maxx, height[top_index]*(s.empty()? i: i-s.top()-1));
      }
    }
    return maxx;
  }
};