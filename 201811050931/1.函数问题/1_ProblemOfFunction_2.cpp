#include<iostream>
using namespace std;

void fun(int a,int b,int &c)
{
	c=b/10+b%10*100+a/10*10+a%10*1000;
}

int main()
{
	int a,b,c;
	cin>>a>>b;
	fun(a,b,c);
	cout<<c;
} 
