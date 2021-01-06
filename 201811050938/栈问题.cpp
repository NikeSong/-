#include<iostream>
#include<stack>
#include<string>
using namespace std;

string getback(string s); 
int count(string str); 
bool compare(char a, char b); //比较两个运算符的优先级
int main()

{
	string str1;
	cout << "请输入一个多项式表达式：" << endl;
	cin >> str1;
	cout << endl;
	string str2 = getback(str1); 
	cout << "输出多项式计算结果为：" << endl;
	cout <<count(str2) << endl;
	return 0;
}
string getback(string s) 
{
	string res;
	stack<char> st;
	int i,size = s.size();
	char temp;
		for (i = 0; i < size; i++)
		{
			if (s[i] != '('&&s[i] != ')'&&s[i] != '+'&&s[i] != '*') 
				res += s[i];
			if (s[i] == '(')
				st.push(s[i]); 
			if (s[i] == '+'||s[i]=='*')
			{
				if (st.empty())
					st.push(s[i]); 
				else 
				{
					while (1)
					{
						temp = st.top();
						if (compare(s[i], temp))
						{
							st.push(s[i]);
							break;
						}
						else
						{
							res += temp;
							st.pop();
							if (st.empty())
							{
								st.push(s[i]);
								break;
							}
						}
					}
				}
			}
			if (s[i] == ')')
			{
				while (st.top() != '(')
				{
					res += st.top();
					st.pop();
				}
				st.pop(); 
			}
		}
		while (!st.empty()) 
		{
			res += st.top();
			st.pop();
		}
		return res; //转换后的算术表达式
}

bool compare(char a, char b) //比较两个运算符的优先级
{

//加法
	if (a == '+'&&b == '+')
		return false;
	if (a == '+'&&b == '*')
		return false;
	if (a == '+'&&b == '(')
		return true;
	//乘法
	if (a == '*'&&b == '+')
		return true;
	if (a == '*'&&b == '*')
		return false;
	if (a == '*'&&b == '(')
		return true;
	return false;
}

int count(string str) //根据后缀算术表达式计算值
{
	stack<int> st;
	int a,b,i,size = str.size();
	for (i = 0; i < size; i++)
	{
		if (str[i] != '+'&&str[i] != '*')
			st.push(str[i] - '0');
		if (str[i] == '+') //执行加法
		{
			a = st.top();
			st.pop();
			b = st.top();
			st.pop();
			st.push(a + b); 
		}
		if (str[i] == '*') //执行乘法
		{
			a = st.top();
			st.pop();
			b = st.top();
			st.pop();
			st.push(a*b); 
		}
	}
	return st.top(); //返回计算结果
}
