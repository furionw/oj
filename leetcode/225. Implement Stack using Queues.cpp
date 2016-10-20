class Stack 
{
public:
    void push(int x) 
    {
        q.push(x);
    }

    void pop() 
    {
        queue<int> tem_q;
        while( q.size() > 1)
        {
            tem_q.push(q.front());
            q.pop();
        }
        q = tem_q;
    }

    int top() 
    {
        auto res = q.front();
        queue<int> tem_q;        
        while(! q.empty())
        {
            res = q.front();            
            tem_q.push(res);
            q.pop();
        }
        q = tem_q;
        return res;
    }

    bool empty() 
    {
        return q.empty();
    }

private:
    queue<int> q;
};
