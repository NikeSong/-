#include<iostream>
#include<algorithm>
using namespace std;

struct node {
    int id;
    int chinese;
    int math;
    int english;
    int total;//�����������
	}stu[300],temp;
	bool cmp(node a, node b) {
    if (a.total != b.total) {
        return a.total > b.total;//�ȱȽ��ܷ�
    }
    else if (a.chinese != b.chinese)
    {
        return a.chinese > b.chinese;//���ܷ���ͬ�ٱȽ����ĳɼ�
    }
    return a.id < b.id; //���ֺܷ����ĳɼ���ͬ�ٱȽ�ѧ��
}
int main()
{
    int n,i,j;
	cout<<"������ѧ������nΪ��";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        stu[i].id = (i+1);
		cout<<"��ֱ�����ѧ�������ġ���ѧ��Ӣ��ɼ�Ϊ��";
        cin >> stu[i].chinese >> stu[i].math >> stu[i].english; 
        stu[i].total = stu[i].chinese + stu[i].math + stu[i].english;
    }
    sort(stu, stu + n, cmp);
    for (i=0; i<5; i++) {
        cout<<"����Ϊ��" << stu[i].id << " " << stu[i].total << endl;
    }
}
