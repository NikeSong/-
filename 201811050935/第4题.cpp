#include<iostream.h>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;

int main()
{
	int m,n,i,j;
	cout<<"请输入mn";
cin>>m>>n;//字符串地图的规模；
	char a[20][20];
cout<<"请输入字符串地图";
getchar();
for(i=0;i<m;i++)
gets(a[i]);

cout<<"请输入周期数";
int c;//经历了几个周期；
cin>>c;

while(c--)//开始寻找整个地图中的‘X’并且按照要求改变其相邻位置的元素；
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

for(i=0;i<m;i++)//将需要变为‘Y’的元素直接变成‘X’;
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