// Copyright 2017 Qi Wang
// Date: 2017-01-10
class MinStack {
 public:
  void push(int x) {
    origin_stk_.push(x);
    if (min_stk_.empty() || x <= min_stk_.top()) {
      min_stk_.push(x);
    }
  }
    
  void pop() {
    if (origin_stk_.top() == min_stk_.top()) {
      min_stk_.pop();
    }
    origin_stk_.pop();
  }
    
  int top() {
    return origin_stk_.top();
  }
    
  int getMin() {
    return min_stk_.top();
  }

 private:
  stack<int> origin_stk_, min_stk_;
};

// Date: ...
class MinStack 
{
public:
    void push(int x) 
    {
        s.push(x);        
        if (min_s.empty() || x<=min_s.top() )
        {
            min_s.push(x);                          
        }
    }

    void pop() 
    {
        if (min_s.top() == s.top())
        {
            s.pop();
            min_s.pop();
        } else
        {
            s.pop();
        }
    }

    int top() 
    {
        return s.top();
    }

    int getMin() 
    {
        return min_s.top();
    }

private:
    stack<int> s;
    stack<int> min_s;
};
