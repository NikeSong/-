#include<iostream>
using namespace std;

int fun(int a,int b)
{
	int c;
	return c=b/10+b%10*100+a/10*10+a%10*1000;
}

int  main()
{
	int a,b;
	cin>>a>>b;
	int c=fun(a,b);
	cout<<c;
	return 0;
} 



