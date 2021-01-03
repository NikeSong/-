#include"teacher_h.h"
using namespace std;

/*  其他函数的定义  */


char show_menu()
{
	char s;
	teac a;
	system("cls");
	a.head_dis();
	cout<<"         1. 教 师 库 管 理"<<endl<<endl<<endl<<endl;
	cout<<"         2. 班 级 库 管 理"<<endl<<endl<<endl<<endl;
	cout<<"         3. 课 程 库 管 理"<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"Tips: 按菜单序号以进入操作 "<<endl;
	s=getch();
	system("cls");
	return s;
}


char show_menu(string name)
{
	char s;
	teac a;
	system("cls");
	a.head_dis();
	cout<<"         1. 插 入 "<<name<<" 信 息"<<endl<<endl<<endl<<endl;
	cout<<"         2. 删 除 "<<name<<" 信 息"<<endl<<endl<<endl<<endl;
	cout<<"         3. 查 询 "<<name<<" 信 息"<<endl<<endl<<endl;
	cout<<"Tips: 输入菜单序号以进入操作, 按0返回"<<endl;
	s=getch();
	system("cls");
	return s;
}



int main()
{
	/* database variation */
	MYSQL mysql,*sock;    // 定义数据库连接的句柄，它被用于几乎所有的 MySQL 函数
    
	teac teac_manu;
	cla class_manu;
	cour course_manu;
	

	/* 进行菜单转换, 直到程序被关闭 */
	while(1)
	{
		/* init_database */
		mysql_init(&mysql);
		/* connect database */
		if (!(sock = mysql_real_connect(&mysql,"localhost","root","111474","softexp",0,NULL,0)))//open database
		{
			fprintf(stderr,"Couldn't connect to engine!  %s", mysql_error(&mysql));
			perror("");
			exit(1);
		}
		char c=show_menu();
		if(c=='1') 
		{
			char s=show_menu("教 师");
			switch(s)
			{
			case '1':teac_manu.insert_teach_data(mysql);break;
			case '2':teac_manu.delete_teach_data(mysql,sock);break;
			case '3':teac_manu.display_teach_data(sock);break;
			}
		}
		else if(c=='2')
		{
			char s=show_menu("班 级");
			switch(s)
			{
			case '1':class_manu.insert_cla_data(mysql);break;
			case '2':class_manu.delete_cla_data(mysql,sock);break;
			case '3':class_manu.display_cla_data(sock);break;
			}
		}
		else
		{
			char s=show_menu("课 程");
			switch(s)
			{
			case '1':course_manu.insert_cour_data(mysql);break;
			case '2':course_manu.delete_cour_data(mysql,sock);break;
			case '3':course_manu.display_cour_data(sock);break;
			}
		}
		mysql_close(sock);
	}
	return 0;
}