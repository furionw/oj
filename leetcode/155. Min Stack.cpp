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