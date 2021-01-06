#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int *fun(int a,int b)
{
	int *p;//通过指针型参数将新数传给主函数
    p=(int*)malloc(sizeof(int));
	int a1=a%10;//a的个位数
	int a2=a/10;//a的十位数
	int b1=b%10;//b的个位数
	int b2=b/10;//b的十位数
	*p=a1*1000+b1*100+a2*10+b2;

     
     return p;
}

int main()
{
    int a,b;
    int *c;
    cout<<"请输入整数a为：";
	cin>>a;
	
	cout<<"请输入整数b为：";
	cin>>b;

    c=fun(a,b);
    cout<<"输出的C为："<<*c<<endl;
    free(c);
}

