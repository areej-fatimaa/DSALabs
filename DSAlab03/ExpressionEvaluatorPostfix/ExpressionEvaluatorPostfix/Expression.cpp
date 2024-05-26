#include <stdio.h>
#include <string>
#include <stack>
#include <iostream>
using namespace std;
string Evaluate(string s);
int Calculate(string s);
void insertionSort();

int main()
{
	insertionSort();
}
void insertionSort()
{
	int arr[4] = { 1,2,8,5,};
	for (int i = 1; i < 4; i++)
	{
		int current = arr[i];
		int j = i - 1;
		while (arr[j] > current && j > 0)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = current;
	}
	for (int i = 0;i<4; i++)
	{
		cout << arr[i] << endl;
	}
}
string Evaluate(string s)
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
int Calculate(string s)
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
