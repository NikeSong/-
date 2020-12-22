#include<iostream>
#include<cstdlib>
using namespace std;
int *fun(int a,int b)
{
	int *p;
	p=(int*)malloc(sizeof(int));
	*p=b/10+b%10*100+a/10*10+a%10*1000;
	return p;
}

int main()
{
	int a,b;
	int *c;
	cin>>a>>b;
	c=fun(a,b);
	cout<<*c;
	free(c);
}


