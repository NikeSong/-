#include"teacher_h.h"
using namespace std;

/*  ���������Ķ���  */


char show_all_menu()
{
	char s;
	teac a;
	system("cls");
	a.show_head();
	cout<<"         1. �� ʦ �� �� ��"<<endl<<endl<<endl<<endl;
	cout<<"         2. �� �� �� �� ��"<<endl<<endl<<endl<<endl;
	cout<<"         3. �� �� �� �� ��"<<endl<<endl<<endl<<endl;
	cout<<"         4. ѡ �� �� Ϣ   "<<endl<<endl<<endl<<endl;
	cout<<"         5. �� Ϣ �� �� չ ʾ"<<endl<<endl<<endl<<endl;

	cout<<"Tips: ���˵�����Խ������ "<<endl;
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
	cout<<"         1. �� �� "<<name<<" �� Ϣ"<<endl<<endl<<endl<<endl;
	cout<<"         2. ɾ �� "<<name<<" �� Ϣ"<<endl<<endl<<endl<<endl;
	cout<<"         3. �� ѯ "<<name<<" �� Ϣ"<<endl<<endl<<endl<<endl;
	cout<<"         4. �� �� "<<name<<" �� Ϣ"<<endl<<endl<<endl<<endl;
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
		int c;
		c=show_all_menu();
		char ssn[10];
		if(c==1) strcpy(ssn,"�� ʦ");
		else if(c==2) strcpy(ssn,"�� ��");
		else if(c==3) strcpy(ssn,"�� ��");
		else strcpy(ssn,"ѡ ��");
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