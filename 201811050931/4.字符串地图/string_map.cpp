#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;

int main()
{
	//输入 
	int col,rank;
	cin>>col>>rank;
	char a[50][50];
	getchar();
	for(int i=0;i<rank;i++)
		gets(a[i]);
	
	int n;
	cin>>n;
	//开始仿真
	while(n--)
	{
		for(int i=0;i<rank;i++)
		{
			for(int j=0;j<col;j++)
			{
				if(a[i][j]=='X')
				{
					if(i-1>=0 && a[i-1][j]!='P' && a[i-1][j]!='X') a[i-1][j]='Y';	
					if(j-1>=0 && a[i][j-1]!='P' && a[i-1][j]!='X') a[i][j-1]='Y';
					if(i+1<rank && a[i+1][j]!='P' && a[i-1][j]!='X') a[i+1][j]='Y';
					if(j+1<col  && a[i][j+1]!='P' && a[i-1][j]!='X') a[i][j+1]='Y';
				}
			}
		 }
		for(int i=0;i<rank;i++)
		{
			for(int j=0;j<col;j++)
			{
				if(a[i][j]=='Y') a[i][j]='X';
			}
		}
	}
	for(int i=0;i<rank;i++)
	cout<<a[i]<<endl;
	
}




