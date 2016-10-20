class Solution 
{
public:
    bool isValid(string s) 
    {
        stack<char> ss;

        for (auto it = s.begin(); it != s.end(); ++ it)
        {
            if (*it=='(' || *it=='[' || *it=='{')
            {
                ss.push(*it);
            } else if ((ss.empty()==false)
              && ((*it==')'&&ss.top()=='(') || (*it==']'&&ss.top()=='[') || (*it=='}'&&ss.top()=='{')))
            {
                ss.pop();
            } else 
            {
                return false;
            }
        }

        return ss.empty();
    }
};