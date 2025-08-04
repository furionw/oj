// 2025-08-04
// Method 2: two pointers. refer to the Editorial
class Solution {
 public:
  int trap(vector<int>& height) {
    int n = height.size();
    int leftmost = height[0];
    int rightmost = height.back();
    int result = 0;
    for (int l = 1, r = n - 2; l <= r; ) {
      if (leftmost <= rightmost) {
        result += max(0, leftmost - height[l]);
        leftmost = max(leftmost, height[l]);
        ++l;
      } else {
        result += max(0, rightmost - height[r]);
        rightmost = max(rightmost, height[r]);
        --r;
      }
    }
    return result;
  }
};

// 2025-08-04
// Method 1: array
class Solution {
 public:
  int trap(vector<int>& height) {
    int n = height.size();
    vector<int> leftmost(n, 0);
    for (int i = 1; i < n; ++i) {
      leftmost[i] = max(leftmost[i - 1], height[i - 1]);
    }
    int result = 0;
    int rightmost = 0;
    for (int i = n - 2; i >= 0; --i) {
      rightmost = max(rightmost, height[i + 1]);
      result += max(0, min(leftmost[i], rightmost) - height[i]);
    }
    return result;
  }
};

// 2025-08-04
class Solution {
 public:
  int trap(vector<int>& height) {
    int n = height.size();
    vector<int> leftmost(n, 0);
    auto rightmost = leftmost;
    for (int i = 1; i < n; ++i) {
      leftmost[i] = max(leftmost[i - 1], height[i - 1]);
    }
    for (int i = n - 2; i >= 0; --i) {
      rightmost[i] = max(rightmost[i + 1], height[i + 1]);
    }

    int result = 0;
    for (int i = 1; i < n - 1; ++i) {
      result += max(0, min(leftmost[i], rightmost[i]) - height[i]);
    }
    return result;
  }
};

// Date: 2022-11-04
class Solution {
 public:
  int trap(vector<int>& height) {
    int n = height.size();
    vector<int> leftmost;
    int maxx = 0;
    for (int h : height) {
      leftmost.push_back(maxx);
      maxx = max(h, maxx);
    }
    maxx = 0;
    vector<int> rightmost(n, 0);
    for (int i = height.size() - 1; i >= 0; --i) {
      rightmost[i] = maxx;
      maxx = max(height[i], maxx);
    }
    int result = 0;
    for (size_t i = 0; i < height.size(); ++i) {
      result += max(0, min(leftmost[i], rightmost[i]) - height[i]);
    }
    return result;
  }
};

// Date: 2017-10-24
class Solution {
 public:
  int trap(vector<int>& height) {
    if (height.size() < 3) return 0;
    int n = height.size();
    vector<int> leftmost(n, 0), rightmost(n, 0);
    for (int i = 1; i < n; ++i) {
      leftmost[i] = max(leftmost[i - 1], height[i - 1]);
    }
    for (int i = n - 2; i >= 0; --i) {
      rightmost[i] = max(rightmost[i + 1], height[i + 1]);
    }
    int result = 0;
    for (int i = 1; i < n - 1; ++i) {
      result += max(min(leftmost[i], rightmost[i]) - height[i], 0);
    }
    return result;
  }
};

// Date: 2017-07-17
class Solution {
 public:
  int trap(vector<int>& height) {
    if (height.size() <= 1) return 0;
    vector<int> leftmost(height.size(), 0), rightmost(height.size(), 0);
    for (size_t i = 1; i < height.size(); ++i) {
      leftmost[i] = max(leftmost[i - 1], height[i - 1]);
    }
    for (int i = height.size() - 2; i >= 0; --i) {
      rightmost[i] = max(rightmost[i + 1], height[i + 1]);
    }
    int result = 0;
    for (size_t i = 1; i < height.size() - 1; ++i) {
      result += max(min(leftmost[i], rightmost[i]) - height[i], 0);
    }
    return result;
  }
};

// Date: 2016-11-02
// Last modified: 2017-01-03
class Solution {
 public:
  int trap(vector<int>& height) {
    if (height.empty()) return 0;
    // Writing standard C++ code via using vector instead of length variable
    // array on 2017-01-03.
    vector<int> leftmost(height.size()), rightmost(height.size());
    for (int i = 0, max = 0; i < height.size(); ++i) {
      leftmost[i] = max;
      max = ::max(max, height[i]);
    }
    for (int i = height.size() - 1, max = 0; i >= 0; --i) {
      rightmost[i] = max;
      max = ::max(max, height[i]);
    }
    int res = 0;
    for (size_t i = 1; i < height.size() - 1; ++i)
      if (min(leftmost[i], rightmost[i]) > height[i])
        res += min(leftmost[i], rightmost[i]) - height[i];
    return res;
  }
};

// Date: 2014-07
class Solution 
{
public:
    int trap(int A[], int n) 
    {
    	int sum = 0;
		vector<int> leftmost(n, 0), rightmost(n, 0);

		for (int i = 0, maxx = 0; i < n; ++ i)
		{
			leftmost[i] = maxx;
			maxx = maxx>A[i]? maxx: A[i];
		}
		for (int i = n-1, maxx = 0; i >= 0; -- i)
		{
			rightmost[i] = maxx;
			maxx = maxx>A[i]? maxx: A[i];
		}
		for (int i = 1; i < n-1; ++ i)
		{
			if (min(leftmost[i], rightmost[i]) > A[i])
			{
				sum += min(leftmost[i], rightmost[i]) - A[i];
			}
		}

		return sum;
    }
};