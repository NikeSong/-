#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;


typedef struct
{
    int num;
    int chi;
    int mat;
    int eng;
    int tot;
}stud;

//排序程序定义 
struct order1
{
    bool operator()(const stud &a1,const stud &a2)
    const
    {
        if(a1.tot>a2.tot) return true;
		else if(a1.tot==a2.tot)
		{
			if(a1.chi>a2.chi) return true;
			else if(a1.chi==a2.chi)
			{
				if(a1.num<a2.num) return true;
				return false;
			}
			return false;
		}
		return false;
    }
};



const int max_num=100; 
int main()
{
	//建立信息库
	stud a[max_num];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].chi>>a[i].mat>>a[i].eng;
		a[i].num=i;
		a[i].tot=a[i].chi+a[i].mat+a[i].eng;
	}
	sort(a+1,a+n+1,order1());
	cout<<"rank："<<endl; 
	for(int i=1;i<6;i++)
		cout<<a[i].num<<"     "<<a[i].tot<<endl;
}



