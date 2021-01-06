#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;

int main()
{
   
   int h,l;
   cout<<"请输入行数h为：";
   cin>>h;
   cout<<"请输入列数l为：";
   cin>>l;
   char a[50][50];
   getchar();
   for(int i=0;i<l;i++)
   gets(a[i]);

   int n;
   cout<<"感染次数n为：";
   cin>>n;
 
   while(n--)
   {
      for(int i=0;i<l;i++)
      {
         for(int j=0;j<h;j++)
         {
             if(a[i][j]=='X')
             {
                 if(i-1>=0 && a[i-1][j]!='P' && a[i-1][j]!='X') a[i-1][j]='F'; 
                 if(j-1>=0 && a[i][j-1]!='P' && a[i-1][j]!='X') a[i][j-1]='F';
                 if(i+1<l && a[i+1][j]!='P' && a[i-1][j]!='X') a[i+1][j]='F';
                 if(j+1<h  && a[i][j+1]!='P' && a[i-1][j]!='X') a[i][j+1]='F';
            }
         }
      }
      for(int w=0;w<l;w++)
      {
          for(int j=0;j<h;j++)
          {
             if(a[w][j]=='F') a[w][j]='X';
          }
      }
    }
    for(int w=0;w<l;w++)
    cout<<"输出："<<a[w]<<endl;
	return 0;
}

