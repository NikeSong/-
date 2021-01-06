#include<iostream>
#include<stack>
#include<string>
using namespace std;

string getback(string s); 
int count(string str); 
bool compare(char a, char b); //�Ƚ���������������ȼ�
int main()

{
	string str1;
	cout << "������һ������ʽ���ʽ��" << endl;
	cin >> str1;
	cout << endl;
	string str2 = getback(str1); 
	cout << "�������ʽ������Ϊ��" << endl;
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
		return res; //ת������������ʽ
}

bool compare(char a, char b) //�Ƚ���������������ȼ�
{

//�ӷ�
	if (a == '+'&&b == '+')
		return false;
	if (a == '+'&&b == '*')
		return false;
	if (a == '+'&&b == '(')
		return true;
	//�˷�
	if (a == '*'&&b == '+')
		return true;
	if (a == '*'&&b == '*')
		return false;
	if (a == '*'&&b == '(')
		return true;
	return false;
}

int count(string str) //���ݺ�׺�������ʽ����ֵ
{
	stack<int> st;
	int a,b,i,size = str.size();
	for (i = 0; i < size; i++)
	{
		if (str[i] != '+'&&str[i] != '*')
			st.push(str[i] - '0');
		if (str[i] == '+') //ִ�мӷ�
		{
			a = st.top();
			st.pop();
			b = st.top();
			st.pop();
			st.push(a + b); 
		}
		if (str[i] == '*') //ִ�г˷�
		{
			a = st.top();
			st.pop();
			b = st.top();
			st.pop();
			st.push(a*b); 
		}
	}
	return st.top(); //���ؼ�����
}
