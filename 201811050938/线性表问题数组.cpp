#include<iostream>
#include<cstring>
using namespace std;
const int max_num=1000;


int fun(int m,int n)
{
     int a[max_num];
     memset(a,0,sizeof(a));
     int i=0;
     for(int d=1;d<m;d++)
     {
          for(int j=0;j<n;j++)
          {
               if(a[(i+1)%m]!=0)
               {
                    while(a[(i+1)%m]!=0)
               {
               i=(i+1)%m;
          }
                    i=(i+1)%m;
                   }
               else 
               {
                    i=(i+1)%m;
               }
           }
          a[i]=1;
          
     }
     int s=999;
     for(i=0;i<m;i++)
     {
          if(a[i]==0) s=i+1;
     }
     return s;
}

int main()
{
     int m,n;
	 cout<<"请输入猴子个数m为：";
	 cin>>m;
     cout<<"请输入淘汰数n为：";
     cin>>n;
     int i=fun(m,n);
     cout<<"猴子大王是： "<<i<<endl;
}
