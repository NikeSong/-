#include"teacher_h.h"
using namespace std;

/*  ���������Ķ���  */


char show_menu()
{
	char s;
	teac a;
	system("cls");
	a.head_dis();
	cout<<"         1. �� ʦ �� �� ��"<<endl<<endl<<endl<<endl;
	cout<<"         2. �� �� �� �� ��"<<endl<<endl<<endl<<endl;
	cout<<"         3. �� �� �� �� ��"<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"Tips: ���˵�����Խ������ "<<endl;
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
	cout<<"         1. �� �� "<<name<<" �� Ϣ"<<endl<<endl<<endl<<endl;
	cout<<"         2. ɾ �� "<<name<<" �� Ϣ"<<endl<<endl<<endl<<endl;
	cout<<"         3. �� ѯ "<<name<<" �� Ϣ"<<endl<<endl<<endl;
	cout<<"Tips: ����˵�����Խ������, ��0����"<<endl;
	s=getch();
	system("cls");
	return s;
}



int main()
{
	/* database variation */
	MYSQL mysql,*sock;    // �������ݿ����ӵľ�����������ڼ������е� MySQL ����
    
	teac teac_manu;
	cla class_manu;
	cour course_manu;
	

	/* ���в˵�ת��, ֱ�����򱻹ر� */
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
			char s=show_menu("�� ʦ");
			switch(s)
			{
			case '1':teac_manu.insert_teach_data(mysql);break;
			case '2':teac_manu.delete_teach_data(mysql,sock);break;
			case '3':teac_manu.display_teach_data(sock);break;
			}
		}
		else if(c=='2')
		{
			char s=show_menu("�� ��");
			switch(s)
			{
			case '1':class_manu.insert_cla_data(mysql);break;
			case '2':class_manu.delete_cla_data(mysql,sock);break;
			case '3':class_manu.display_cla_data(sock);break;
			}
		}
		else
		{
			char s=show_menu("�� ��");
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