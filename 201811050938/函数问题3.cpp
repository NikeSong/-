#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int *fun(int a,int b)
{
	int *p;//ͨ��ָ���Ͳ�������������������
    p=(int*)malloc(sizeof(int));
	int a1=a%10;//a�ĸ�λ��
	int a2=a/10;//a��ʮλ��
	int b1=b%10;//b�ĸ�λ��
	int b2=b/10;//b��ʮλ��
	*p=a1*1000+b1*100+a2*10+b2;

     
     return p;
}

int main()
{
    int a,b;
    int *c;
    cout<<"����������aΪ��";
	cin>>a;
	
	cout<<"����������bΪ��";
	cin>>b;

    c=fun(a,b);
    cout<<"�����CΪ��"<<*c<<endl;
    free(c);
}

