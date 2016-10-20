#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

inline bool is_opeartor(const string& c)
{
	return c.size()==1 && (c[0]=='+' || c[0]=='-' || c[0]=='*' || c[0]=='/');
}

inline int string_to_int(const string& s)
{
	int ret;

	stringstream ss;
	ss << s;
	ss >> ret;

	return ret;
}

int calculate(int op1, int op2, const string& operand)
{
	if (operand[0] == '+')
	{
		return op1 + op2;
	} else if (operand[0] == '-')
	{
		return op1 - op2;
	} else if (operand[0] == '*')
	{
		return op1 * op2;
	} else //
	{
		return op1 / op2;
	}
}

int evalRPN(vector<string> &tokens) 
{
	stack<int> operand;

	for (size_t i = 0; i < tokens.size(); ++ i)
	{
		if (is_opeartor(tokens[i]))
		{
			int op2 = operand.top();
			operand.pop();
			int op1 = operand.top();
			operand.pop();
			operand.push( calculate(op1, op2, tokens[i]) );
		} else
		{
			operand.push( string_to_int(tokens[i]) );
		}
	}

	return operand.top();
}

int main()
{
	vector<string> tokens;
	tokens.push_back("2");
	tokens.push_back("1");
	tokens.push_back("+");
	tokens.push_back("3");
	tokens.push_back("*");
	cout << evalRPN(tokens);

	return 0;
}