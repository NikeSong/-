#include<iostream>
#include<string>
using namespace std;

class Vehicle
{
private://私有
	
protected://将车轮个数和车重放置在保护段中
	string name;
	int wheels;//车轮个数
	int weight;//车重
public://公用段
	Vehicle(int wh, int we, string nm) :wheels(wh), weight(we) { name = nm; }
	void SetWheels(int wh) { wheels = wh; }//车轮个数
	void SetWeight(int we) { weight = we; }//车重
	void SetName(char nm[]) { name = nm; }//车类名
	int GetWheels() const { return wheels; }
	int GetWeight() const { return weight; }
	string GetName() const { return name; }
	void show() const;
};
void Vehicle::show() const//展示类中的数据
{
	cout << "车类：" << name << endl;
	cout << "车轮个数：" << wheels << endl;
	cout << "车重：" << weight << endl;
}
class Car :private Vehicle//私有派生类小车类car
{
protected:
	int passenger_Load;//载人数
public:
	Car(string nm,int wh,int pl, int we) :Vehicle(wh, we, nm), passenger_Load(pl) {}//接收字段：车类，车轮个数，载人数，车重
	void SetPassenger_Load(int pl) { passenger_Load = pl; }
	int GetPassenger_Load() const { return passenger_Load; }
	void show() const;
};
void Car::show() const//展示小汽车类
{
	cout << "车类：" << name << endl;
	cout << "车轮个数：" << wheels << endl;
	cout << "载人数：" << passenger_Load << endl;
	cout << "车重：" << weight << "kg" << endl;
}
class Truck :private Vehicle//私有派生类卡车类truck
{
protected:
	int passenger_Load;//载人数
	int payload;//载重量
public:
	Truck(string nm,int wh,int p, int pd, int we) :Vehicle(wh, we, nm), passenger_Load(p), payload(pd) {}//接收字段：车类，车轮个数，载人数，载重量，车重
	void SetPassenger(int p) { passenger_Load = p; }
	void SetPayLoad(int pd) { payload = pd; }
	int GetPassenger() const { return passenger_Load; }
	int GetPayLoad() const { return payload; }
	void show() const;
};
void Truck::show()const//展示卡车类
{
	cout << "车类：" << name << endl;
	cout << "车轮个数：" << wheels << endl;
	cout << "载人数：" << passenger_Load << endl;
	cout << "载重量：" << payload << "kg" << endl;
	cout << "车重：" << weight << "kg" << endl;
}
int main()
{
	Car car("小汽车",4, 4, 2000);//输入小汽车类数据
	car.show();
	Truck truck("卡车", 8, 2, 4000, 5000);//输入卡车类数据
	truck.show();

	system("PAUSE");
	return 0;
}