#include"teacher_h.h"


/*��ʦ��ĳ�Ա����*/


void teac::head_dis()
{
	cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl<<endl;
	cout<<"                                ��  ʦ  ��  ��  ϵ  ͳ                           "<<endl<<endl;
	cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
	cout<<endl;
}




/*      ��      */
void teac::insert_teach_data(MYSQL &mysql)
{
	while(1)
	{
		head_dis();
		char c;
		char qbuf[256];
		cout<<"�����������ʦ�ţ���ʦ�������Ա�ְ�ƣ��γ�"<<endl;
		char tea_num_s[50],name_s[50],gender_s[50],title_s[50],course_s[50];
		cin>>tea_num_s>>name_s>>gender_s>>title_s>>course_s;
		sprintf(qbuf, "insert into teacher (tea_num,name,gender,title,cors) values ('%s','%s','%s','%s','%s');",tea_num_s,name_s,gender_s,title_s,course_s);
		mysql_query(&mysql,qbuf);
		cout<<"�Ѳ���-   "<<tea_num_s<<' '<<name_s<<' '<<gender_s<<' '<<title_s<<' '<<course_s<<endl;
		cout<<"��0���˳�����1��������"<<endl;
		c=getch();
		if(c=='0') break;
	}
}





/*      ��     */
void teac::display_teach_data(MYSQL *sock)
{
	char qbuf[256];
	MYSQL_ROW row ;  // ���һ�в�ѯ������ַ�������
	sprintf(qbuf,"select * from teacher");//input sql command
	if(mysql_query(sock,qbuf))
	{
		fprintf(stderr,"Query failed! (%s)",mysql_error(sock));
		exit(1);
	}
	MYSQL_RES res; 
	res = *mysql_store_result(sock);
	unsigned short numFields;
	char column[30][40];


	numFields = mysql_num_fields(&res);	//ͳ�� table �ֶ�
	
	for(int i = 0; i < numFields; ++i)	//�����ֶ�
	{
		strcpy(column[i], mysql_fetch_field(&res)->name);
		// printf("%s\n", column[i]);
	}
 	cout<<" the result is: "<<endl;

	while( (row = mysql_fetch_row(&res)) != NULL )	//��ӡÿһ�е�����
	{
		for(int j=0; j<numFields; j++)
		{
			printf("%s = %s\t", column[j], row[j]);
		}
		cout<<endl;
	}

	
    cout<<endl<<endl<<endl<<endl<<"# ��ʦ��Ϣչʾ���� ��0����#"<<endl;
	char c;
	while(1)
	{
		c=getch();
		if(c=='0') break;
	}
	mysql_free_result(&res);
}



/*     ɾ    */
void teac::delete_teach_data(MYSQL &mysql,MYSQL *sock)
{
	while(1)
	{
		head_dis();
		char qbuf[256];
	
		cout<<"please input the number of teacher:"<<endl;
		char tea_nums[50];
		cin>>tea_nums;
		sprintf(qbuf, "delete from teacher where tea_num='%s';",tea_nums);
		mysql_query(&mysql, qbuf);
		if(mysql_query(sock,qbuf))
		{
			fprintf(stderr,"Query failed (%s)",mysql_error(sock));
		}
		else
			cout<<"teacher with number "<<tea_nums<<" has been deleted!"<<endl;
		
		cout<<endl<<"# ��ʦ��Ϣɾ������ ��0���� ��1����#"<<endl;
		char c;
		c=getch();
		if(c=='0') break;
		else continue;
	}

}



void teac::calculate_number()
{


}







/*   �γ���ĳ�Ա����  */

/*   ��  */
void cour::insert_cour_data(MYSQL &mysql)
{
	while(1)
	{
		teac a;
		a.head_dis();
		char c;
		char qbuf[256];
		cout<<"����������γ̺ţ��γ����ơ�����ѧʱ��ʵ��ѧʱ"<<endl;
		char cour_num_s[50],cour_name_s[50];
		double theo_time_s,exp_time_s;
		cin>>cour_num_s>>cour_name_s>>theo_time_s>>exp_time_s;
		double all_time_s=theo_time_s+exp_time_s;
		sprintf(qbuf, "insert into course (cla_num,cla_name,theo_time,expo_time,all_time) values ('%s','%s','%lf','%lf','%lf');",cour_num_s,cour_name_s,theo_time_s,exp_time_s,all_time_s);
		mysql_query(&mysql,qbuf);
		cout<<"�Ѳ���-   "<<cour_num_s<<' '<<cour_name_s<<' '<<theo_time_s<<' '<<exp_time_s<<endl;
		cout<<"��0���˳�����1��������"<<endl;
		c=getch();
		if(c=='0') break;
	}
}



/*  ��  */
void cour::display_cour_data(MYSQL *sock)
{
	char qbuf[256];
	MYSQL_ROW row ;  // ���һ�в�ѯ������ַ�������
	sprintf(qbuf,"select * from course");//input sql command
	if(mysql_query(sock,qbuf))
	{
		fprintf(stderr,"Query failed! (%s)",mysql_error(sock));
		exit(1);
	}
	MYSQL_RES res; 
	res = *mysql_store_result(sock);
	unsigned short numFields;
	char column[30][40];


	numFields = mysql_num_fields(&res);	//ͳ�� table �ֶ�

	for(int i = 0; i < numFields; ++i)	//�����ֶ�
	{
		strcpy(column[i], mysql_fetch_field(&res)->name);
		// printf("%s\n", column[i]);
	}
 	cout<<" the result is: "<<endl;

	while( (row = mysql_fetch_row(&res)) != NULL )	//��ӡÿһ�е�����
	{
		for(int j=0; j<numFields; j++)
		{
			printf("%s = %s\t", column[j], row[j]);
		}
		cout<<endl;
	}

	
    cout<<endl<<endl<<endl<<endl<<"#  �γ���Ϣչʾ���� ��0����#"<<endl;
	char c;
	while(1)
	{
		c=getch();
		if(c=='0') break;
	}
	mysql_free_result(&res);
}




/*    ɾ   */
void cour::delete_cour_data(MYSQL &mysql,MYSQL *sock)
{
	while(1)
	{
		teac a;
		a.head_dis();
		char qbuf[256];
	
		cout<<"please input the number of course:"<<endl;
		char cour_nums[50];
		cin>>cour_nums;
		sprintf(qbuf, "delete from course where cla_num='%s';",cour_nums);
		mysql_query(&mysql, qbuf);
		if(mysql_query(sock,qbuf))
		{
			fprintf(stderr,"Query failed (%s)",mysql_error(sock));
		}
		else
			cout<<"course with number "<<cour_nums<<" has been deleted!"<<endl;
		
		cout<<endl<<"# �γ���Ϣɾ������ ��0���� ��1����#"<<endl;
		char c;
		c=getch();
		if(c=='0') break;
		else continue;
	}

}



/*�༶�����ɾ��*/



void cla::insert_cla_data(MYSQL &mysql)
{
	while(1)
	{
		teac a;
		a.head_dis();
		char c;
		char qbuf[256];
		cout<<"����������༶�ţ��༶��"<<endl;
		char cla_num_s[50],cla_name_s[50];
		cin>>cla_num_s>>cla_name_s;
		sprintf(qbuf, "insert into cla (cla_num,cla_name) values ('%s','%s');",cla_num_s,cla_name_s);
		mysql_query(&mysql,qbuf);
		cout<<"�Ѳ���-   "<<cla_num_s<<' '<<cla_name_s<<endl;
		cout<<"��0���˳�����1��������"<<endl;
		c=getch();
		if(c=='0') break;
	}
}




void cla::display_cla_data(MYSQL *sock)
{
	char qbuf[256];
	MYSQL_ROW row ;  // ���һ�в�ѯ������ַ�������
	sprintf(qbuf,"select * from cla");//input sql command
	if(mysql_query(sock,qbuf))
	{
		fprintf(stderr,"Query failed! (%s)",mysql_error(sock));
		exit(1);
	}
	MYSQL_RES res; 
	res = *mysql_store_result(sock);
	unsigned short numFields;
	char column[30][40];


	numFields = mysql_num_fields(&res);	//ͳ�� table �ֶ�
	
	for(int i = 0; i < numFields; ++i)	//�����ֶ�
	{
		strcpy(column[i], mysql_fetch_field(&res)->name);
		// printf("%s\n", column[i]);
	}
 	cout<<" the result is: "<<endl;

	while( (row = mysql_fetch_row(&res)) != NULL )	//��ӡÿһ�е�����
	{
		for(int j=0; j<numFields; j++)
		{
			printf("%s = %s\t", column[j], row[j]);
		}
		cout<<endl;
	}
    cout<<endl<<endl<<endl<<endl<<"#  �༶��Ϣչʾ���� ��0����#"<<endl;
	char c;
	while(1)
	{
		c=getch();
		if(c=='0') break;
	}
	mysql_free_result(&res);

}




void cla::delete_cla_data(MYSQL &mysql,MYSQL *sock)
{
	while(1)
	{
		teac a;
		a.head_dis();
		char qbuf[256];
	
		cout<<"please input the number of class:"<<endl;
		char cla_nums[50];
		cin>>cla_nums;
		sprintf(qbuf, "delete from cla where cla_num='%s';",cla_nums);
		mysql_query(&mysql, qbuf);
		if(mysql_query(sock,qbuf))
		{
			fprintf(stderr,"Query failed (%s)",mysql_error(sock));
		}
		else
			cout<<"teacher with number "<<cla_nums<<" has been deleted!"<<endl;
		
		cout<<endl<<"# �༶��Ϣɾ������ ��0���� ��1����#"<<endl;
		char c;
		c=getch();
		if(c=='0') break;
		else continue;
	}

}

