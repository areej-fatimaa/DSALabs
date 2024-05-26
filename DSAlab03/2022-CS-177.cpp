#include <stdio.h>
#include<iostream>
#include<stack>
using namespace std;
int main()
{
string s = "((3*2))*(4-(9+2))";
string postfix,postfix;
postfix = EvaluatePrefix(s);
cout << postfix<<endl;
cout << CalculatePrefix(postfix)<<endl;
postfix=EvaluatePostfix(s);
cout<<postfix<<endl;
cout<<CalculatePostfix(postfix)<<endl;
return 0;
}
int presedence(char c)
{
	if (c == '/' || c == '*')
	{
		return 2;
	}
	else if (c == '+' || c == '-')
	{
		return 1;
	}
	else
		return 0; 
}
string EvaluatePrefix(string s)
{
	reverse(s.begin(), s.end());
	stack<char> stack;
	string str = "";
	if (s.size() != 0)
	{
	    for (int i = 0; i < s.size(); i++)
		{
			if (isdigit(s[i]))
			{
				str += s[i];
			}
	       else if (s[i] == '+' || s[i] == '*' || s[i] == '/' || s[i] == '-' || s[i] == '(' || s[i] == ')')
			{
			 if (s[i] == ')')
			{
				stack.push(s[i]);
			}
			else if (s[i] == '(')
			{
				while (!stack.empty()&&stack.top() != ')')
				{
					str += stack.top();
					stack.pop();
				}
				if (!stack.empty())
				{
					stack.pop();
				}

			}
			else
			{
				while (!stack.empty() && presedence(stack.top()) > presedence(s[i]))
				{
					str += stack.top();
					stack.pop();
				}
				stack.push(s[i]);
			}
			}
		}
		while (!stack.empty())
		{
			str += stack.top();
			stack.pop();
		}
		reverse(str.begin(), str.end());
		return str;
	}
	return "";
} 
int CalculatePrefix(string s)
{
		stack <int> stack;
	if (s.size() != 0)
	{
		for (int i =s.size(); i>=0; i--)
		{
			if (isdigit(s[i]))
			{
				stack.push(s[i] - '0');
			}
			else if (s[i] == '+')
			{
				int temp = stack.top();
				stack.pop();
				int temp2 = stack.top();
				stack.pop();
				stack.push(temp + temp2);
			}
			else if (s[i] == '-')
			{
				int temp = stack.top();
				stack.pop();
				int temp2 = stack.top();
				stack.pop();
				stack.push(temp - temp2);
			}
			else if (s[i] == '*')
			{
				int temp = stack.top();
				stack.pop();
				int temp2 = stack.top();
				stack.pop();
				stack.push(temp * temp2);
			}
			else if (s[i] == '/')
			{
				int temp = stack.top();
				stack.pop();
				int temp2 = stack.top();
				stack.pop();
				stack.push(temp / temp2);
			}
		}
		return stack.top();
	}
	return 0;
}
string EvaluatePostfix(string s)
{
	stack<char> stack;
	string str = "";
	if (s.size()!=0)
	{
 		for (int i = 0; i < s.size(); i++)
		{
 			if (isdigit(s[i]))
			{
				str += s[i];
			}
			else if (s[i] == '+' || s[i] == '*' || s[i] == '/' || s[i] == '-' || s[i] == '(' || s[i] == ')')
			{
		        if (s[i] == ')')
			    {
				while (stack.top() != '(')
				{
					str += stack.top();
					stack.pop();
				}
				stack.pop();
			    }
			    else if (stack.empty() || stack.top() == '('||s[i]=='(')
				{
					stack.push(s[i]);
				}
				else if (stack.top() == '/' || stack.top() == '*'&&(s[i]=='-'||s[i]=='+'))
				{
						char tempStr{};
						tempStr = stack.top();
						stack.pop();
						stack.push(s[i]);
							stack.push(tempStr);
				}
			}
		}
		while (!stack.empty())
		{
			str += stack.top();
			stack.pop();
		}
		return str;
	}
	return "";
}
int CalculatePostfix(string s)
{
	stack <int> stack;
	if (s.size() != 0)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (isdigit(s[i]))
			{
				stack.push(s[i] - '0');
			}
			else if (s[i] == '+')
			{
				int temp = stack.top();
				stack.pop();
				int temp2 = stack.top();
				stack.pop();
				stack.push(temp2 + temp);
			}
			else if (s[i] == '-')
			{
				int temp = stack.top();
				stack.pop();
				int temp2 = stack.top();
				stack.pop();
				stack.push(temp2 - temp);
			}
			else if (s[i] == '*')
			{
				int temp = stack.top();
				stack.pop();
				int temp2 = stack.top();
				stack.pop();
				stack.push(temp2 * temp);
			}
			else if (s[i] == '/')
			{
				int temp = stack.top();
				stack.pop();
				int temp2 = stack.top();
				stack.pop();
				stack.push(temp2 / temp);
			}
		}
		return stack.top();
	}
	return 0;
}