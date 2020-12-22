#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

typedef struct mon
{
	int k;
	mon* fron;
	mon* next;
}mons;



int fun(int m,int n)
{
//建立list 
	mons *h,*p;
	p=(mons*)malloc(sizeof(mons));
	p->k=1;
	h=p;
	for(int i=1;i<m;i++)
	{
		mons *n=(mons*)malloc(sizeof(mons));
		p->next=n;
		n->fron=p;
		p=p->next;
		p->k=i+1;
	}
	p->next=h;
	h->fron=p;
	p=h;
//选猴王 
	for(int i=0;i<m-1;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(p->next->k!=-1)
			{
				p=p->next;
			}
			else
			{
				while(p->next->k==-1)
				{
					p=p->next;
				}
				p=p->next;
			}
		}
		mons *f=p->fron;
		mons *b=p->next;
		f->next=b;
		b->fron=f;
		free(p);
		p=f;
	}
	return p->k;
}

int main()
{
	int m,n;
	cin>>m>>n;
	int i=fun(m,n);
	cout<<"monkey king is number "<<i<<endl;
}





