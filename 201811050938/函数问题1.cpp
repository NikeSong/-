#include<iostream>
#include<string>
using namespace std;

int fun(int a,int b)
{
	int c;
	int a1=a%10;//a�ĸ�λ��
	int a2=a/10;//a��ʮλ��
	int b1=b%10;//b�ĸ�λ��
	int b2=b/10;//b��ʮλ��
	c=a1*1000+b1*100+a2*10+b2;
	return c;
}
int main() {


	int a,b;
	cout<<"����������aΪ��";
	cin>>a;
	
	cout<<"����������bΪ��";
	cin>>b;

	int c=fun(a,b);
	cout<<"�����CΪ��"<<c<<endl;


	return 0;
}