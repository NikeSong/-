#include<iostream.h>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;

int main()
{
	int m,n,i,j;
	cout<<"������mn";
cin>>m>>n;//�ַ�����ͼ�Ĺ�ģ��
	char a[20][20];
cout<<"�������ַ�����ͼ";
getchar();
for(i=0;i<m;i++)
gets(a[i]);

cout<<"������������";
int c;//�����˼������ڣ�
cin>>c;

while(c--)//��ʼѰ��������ͼ�еġ�X�����Ұ���Ҫ��ı�������λ�õ�Ԫ�أ�
{
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[i][j]=='X')
				{
					if(i-1>=0 && a[i-1][j]!='P' && a[i-1][j]!='X') a[i-1][j]='Y';	
					if(j-1>=0 && a[i][j-1]!='P' && a[i-1][j]!='X') a[i][j-1]='Y';
					if(i+1<m && a[i+1][j]!='P' && a[i-1][j]!='X') a[i+1][j]='Y';
					if(j+1<n  && a[i][j+1]!='P' && a[i-1][j]!='X') a[i][j+1]='Y';
				}
			}
		 }

for(i=0;i<m;i++)//����Ҫ��Ϊ��Y����Ԫ��ֱ�ӱ�ɡ�X��;
		{
			for(j=0;j<c;j++)
			{
				if(a[i][j]=='Y')
					a[i][j]='X';
			}
		}
	}

	for(i=0;i<m;i++)
	cout<<a[i]<<endl;
	return 0;
}