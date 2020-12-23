#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
class vehicle
{
	protected:
		int wheels;
		double weight;
	public:
		vehicle(int wh,double we)
		{
			wheels=wh;
			weight=we;
		}
		vehicle(){}
		void cout_vehicle()
		{
			cout<<"number of wheels:"<<wheels<<endl;
			cout<<"weight:"<<weight<<endl;
		}
		
};

class car :private vehicle
{
	public:
		int passenger_load;
		car(int p,int wh,double we)
		{
			passenger_load=p;
			wheels=wh;
			weight=we;
		}
		void cout_car()
		{
			this->cout_vehicle();
			cout<<"passenger number maxmum:"<<this->passenger_load<<endl;
		}
};

class truck :private vehicle
{
	public:
		int passenger_load;
		double payload;
		truck(int pa,double pay,int wh,double we)
		{
			passenger_load=pa;
			payload=pay;
			wheels=wh;
			weight=we;
		}
		void cout_truck()
		{
			this->cout_vehicle();
			cout<<"passenger number maxmum:"<<this->passenger_load<<endl;
			cout<<"payload£º"<<this->payload<<endl;
		}
};

int main()
{
	vehicle v1(4,203.5);
	v1.cout_vehicle();
	cout<<endl;
	
	car c1(6,120,15);
	c1.cout_car();
	cout<<endl;
	
	truck t1(15,150.2,8,45.5);
	t1.cout_truck();
	cout<<endl;
	
}




