#include<iostream>
#include<string>
using namespace std;

class Vehicle
{
private://˽��
	
protected://�����ָ����ͳ��ط����ڱ�������
	string name;
	int wheels;//���ָ���
	int weight;//����
public://���ö�
	Vehicle(int wh, int we, string nm) :wheels(wh), weight(we) { name = nm; }
	void SetWheels(int wh) { wheels = wh; }//���ָ���
	void SetWeight(int we) { weight = we; }//����
	void SetName(char nm[]) { name = nm; }//������
	int GetWheels() const { return wheels; }
	int GetWeight() const { return weight; }
	string GetName() const { return name; }
	void show() const;
};
void Vehicle::show() const//չʾ���е�����
{
	cout << "���ࣺ" << name << endl;
	cout << "���ָ�����" << wheels << endl;
	cout << "���أ�" << weight << endl;
}
class Car :private Vehicle//˽��������С����car
{
protected:
	int passenger_Load;//������
public:
	Car(string nm,int wh,int pl, int we) :Vehicle(wh, we, nm), passenger_Load(pl) {}//�����ֶΣ����࣬���ָ�����������������
	void SetPassenger_Load(int pl) { passenger_Load = pl; }
	int GetPassenger_Load() const { return passenger_Load; }
	void show() const;
};
void Car::show() const//չʾС������
{
	cout << "���ࣺ" << name << endl;
	cout << "���ָ�����" << wheels << endl;
	cout << "��������" << passenger_Load << endl;
	cout << "���أ�" << weight << "kg" << endl;
}
class Truck :private Vehicle//˽�������࿨����truck
{
protected:
	int passenger_Load;//������
	int payload;//������
public:
	Truck(string nm,int wh,int p, int pd, int we) :Vehicle(wh, we, nm), passenger_Load(p), payload(pd) {}//�����ֶΣ����࣬���ָ�������������������������
	void SetPassenger(int p) { passenger_Load = p; }
	void SetPayLoad(int pd) { payload = pd; }
	int GetPassenger() const { return passenger_Load; }
	int GetPayLoad() const { return payload; }
	void show() const;
};
void Truck::show()const//չʾ������
{
	cout << "���ࣺ" << name << endl;
	cout << "���ָ�����" << wheels << endl;
	cout << "��������" << passenger_Load << endl;
	cout << "��������" << payload << "kg" << endl;
	cout << "���أ�" << weight << "kg" << endl;
}
int main()
{
	Car car("С����",4, 4, 2000);//����С����������
	car.show();
	Truck truck("����", 8, 2, 4000, 5000);//���뿨��������
	truck.show();

	system("PAUSE");
	return 0;
}