#include"teacher_h.h"
using namespace std;

/*  其他函数的定义  */


char show_all_menu()
{
	char s;
	teac a;
	system("cls");
	a.show_head();
	cout<<"         1. 教 师 库 管 理"<<endl<<endl<<endl<<endl;
	cout<<"         2. 班 级 库 管 理"<<endl<<endl<<endl<<endl;
	cout<<"         3. 课 程 库 管 理"<<endl<<endl<<endl<<endl;
	cout<<"         4. 选 课 信 息   "<<endl<<endl<<endl<<endl;
	cout<<"         5. 信 息 综 合 展 示"<<endl<<endl<<endl<<endl;

	cout<<"Tips: 按菜单序号以进入操作 "<<endl;
	s=getch();
	system("cls");
	int c=s-'0';
	return c;
}


int show_menu(string name)
{
	char s;
	teac a;
	system("cls");
	a.show_head();
	cout<<"         1. 插 入 "<<name<<" 信 息"<<endl<<endl<<endl<<endl;
	cout<<"         2. 删 除 "<<name<<" 信 息"<<endl<<endl<<endl<<endl;
	cout<<"         3. 查 询 "<<name<<" 信 息"<<endl<<endl<<endl<<endl;
	cout<<"         4. 修 改 "<<name<<" 信 息"<<endl<<endl<<endl<<endl;
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
		int c;
		c=show_all_menu();
		char ssn[10];
		if(c==1) strcpy(ssn,"教 师");
		else if(c==2) strcpy(ssn,"班 级");
		else if(c==3) strcpy(ssn,"课 程");
		else strcpy(ssn,"选 课");
		if(c==5) teac_manu.displays(sock);
		else
		{
			char s=show_menu(ssn);
			switch(s)
			{
				case '1':teac_manu.insert(mysql,sock,c);break;
				case '2':teac_manu.deletes(mysql,sock,c);break;
				case '3':teac_manu.display_one(sock,c);break;
				case '4':teac_manu.modify(mysql,sock,c);break;
			}
		}
		teac_manu.cal_all_work(mysql,sock);
		mysql_close(sock);
	}
	return 0;
}