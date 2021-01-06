#include<iostream>
#include<algorithm>
using namespace std;

struct node {
    int id;
    int chinese;
    int math;
    int english;
    int total;//定义五个对象
	}stu[300],temp;
	bool cmp(node a, node b) {
    if (a.total != b.total) {
        return a.total > b.total;//先比较总分
    }
    else if (a.chinese != b.chinese)
    {
        return a.chinese > b.chinese;//若总分相同再比较语文成绩
    }
    return a.id < b.id; //若总分和语文成绩相同再比较学号
}
int main()
{
    int n,i,j;
	cout<<"请输入学生个数n为：";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        stu[i].id = (i+1);
		cout<<"请分别输入学生的语文、数学、英语成绩为：";
        cin >> stu[i].chinese >> stu[i].math >> stu[i].english; 
        stu[i].total = stu[i].chinese + stu[i].math + stu[i].english;
    }
    sort(stu, stu + n, cmp);
    for (i=0; i<5; i++) {
        cout<<"排名为：" << stu[i].id << " " << stu[i].total << endl;
    }
}
