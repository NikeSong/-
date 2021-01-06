#include"teacher_h.h"


void teac::show_head()
{
	cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl<<endl;
	cout<<"                                ��  ʦ  ��  ��  ϵ  ͳ                           "<<endl<<endl;
	cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
	cout<<endl;
}




/*      ��      */
void teac::insert(MYSQL &mysql,MYSQL *sock,int tn)
{
	while(1)
	{
		show_head();
		
		char qbuf[256];
		
		switch(tn)
		{
		case 1:{
				cout<<"�����������ʦ�ţ���ʦ�������Ա�ְ��"<<endl;
				char tea_num_s[50],name_s[50],gender_s[50],title_s[50];
				cin>>tea_num_s>>name_s>>gender_s>>title_s;
				sprintf(qbuf, "insert into teacher (tea_num,name,gender,title,work_time) values ('%s','%s','%s','%s',0);",tea_num_s,name_s,gender_s,title_s);
				mysql_query(&mysql,qbuf);
				cout<<"�Ѳ���-   "<<tea_num_s<<' '<<name_s<<' '<<gender_s<<' '<<title_s<<' '<<endl;
				break;
			   }
		case 2:{
				cout<<"����������༶�ţ��༶��"<<endl;
				char cla_num_s[50],cla_name_s[50];
				cin>>cla_num_s>>cla_name_s;
				sprintf(qbuf, "insert into cla (cla_num,cla_name) values ('%s','%s');",cla_num_s,cla_name_s);
				mysql_query(&mysql,qbuf);
				cout<<"�Ѳ���-   "<<cla_num_s<<' '<<cla_name_s<<endl;
				break;
			   }
		case 3:{
				
				cout<<"����������γ̺š��γ����ơ�����ѧʱ��ʵ��ѧʱ���ڿν�ʦ��"<<endl;
				char cour_num_s[50],cour_name_s[50];
				double theo_time_s,exp_time_s;
				char te_nu[50];
				cin>>cour_num_s>>cour_name_s>>theo_time_s>>exp_time_s>>te_nu;
				double all_time_s=theo_time_s+exp_time_s;
				sprintf(qbuf, "insert into course values ('%s','%s',%lf,%lf,0,'%s',%lf);",cour_num_s,cour_name_s,theo_time_s,exp_time_s,te_nu,all_time_s);
				mysql_query(&mysql,qbuf);
				cout<<"�Ѳ���-   "<<cour_num_s<<' '<<cour_name_s<<' '<<theo_time_s<<' '<<exp_time_s<<endl;
			    break;
			   }
		case 4:{
				MYSQL_ROW row ;  
			
				sprintf(qbuf,"SELECT count(*) FROM cou_cla;");//input sql command
				mysql_query(&mysql,qbuf);
				MYSQL_RES res; 
				res = *mysql_store_result(sock);
				unsigned short numFields;
				numFields = mysql_num_fields(&res);	//ͳ�� table �ֶ�
				row = mysql_fetch_row(&res);	//��ӡÿһ�е�����
				cout<<"������������Ϣ�š�ѡ�ΰ༶�ţ�Ҫѡ�Ŀγ̺�"<<endl;
				int nu;
				char cla_id_s[50],cours_id_s[50];
				cin>>nu>>cla_id_s>>cours_id_s;
				sprintf(qbuf, "insert into cou_cla (r_num,cl_id,co_id) values ( %d,'%s','%s');",nu,cla_id_s,cours_id_s);
				mysql_query(&mysql,qbuf);
				cout<<"�Ѳ���-   "<<cla_id_s<<' '<<cours_id_s<<endl;
				break;
			   }
		}
		
		cal_all_work(mysql,sock);
		

		cout<<"��0���˳�����1��������"<<endl;
		
		char c=getch();
		if(c=='0') break;
	}
}


/*     ɾ    */
void teac::deletes(MYSQL &mysql,MYSQL *sock,int tn)
{
	while(1)
	{
		show_head();
		char qbuf[256];
		char a[20],b[20];
		if(tn==1) {strcpy(a,"teacher");strcpy(b,"tea_num");}
		else if (tn==2) {strcpy(a,"cla");strcpy(b,"cla_num");}
		else if(tn==3) {strcpy(a,"course");strcpy(b,"cours_num");}
		else {strcpy(a,"cou_cla");strcpy(b,"r_num");}
		
		printf("please input the number of %s:",a);

		char nums[50];
		cin>>nums;
		sprintf(qbuf, "delete from %s where %s='%s';",a,b,nums);
		mysql_query(&mysql, qbuf);
		if(mysql_query(sock,qbuf))
		{
			fprintf(stderr,"Query failed (%s)",mysql_error(sock));
		}
		else
			cout<<"object with number "<<nums<<" has been deleted!"<<endl;
		
		cal_all_work(mysql,sock);
		cout<<endl<<"# ��Ϣɾ������ ��0���� ��1����#"<<endl;
		char c;
		c=getch();
		if(c=='0') break;
		else continue;
	}

}



/*      ��     */
void teac::displays(MYSQL *sock)
{
	show_head();
	char qbuf[256];
	MYSQL_ROW row ;  // ���һ�в�ѯ������ַ�������

	sprintf(qbuf,"SELECT * FROM teacher LEFT JOIN course ON teacher.tea_num=course.teacher_id; ");//input sql command
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
 	cout<<" the result is: "<<endl<<endl<<endl;
	
	printf("%11s%11s%11s%11s%11s%10s%11s%11s%11s%11s%11s%11s\n","��ʦ��","����","�Ա�","ְ��","������","�γ̺�","�γ���","����","ʵ��","�༶��","��ʦ��","�γ̹�����");
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	while( (row = mysql_fetch_row(&res)) != NULL )	//��ӡÿһ�е�����
	{
		for(int j=0; j<numFields; j++)
		{
			printf("%11s",  row[j]);
		}
		cout<<endl;
	}	
    cout<<endl<<endl<<endl<<endl<<"# ��Ϣչʾ���� ��0����#"<<endl;
	char c;
	while(1)
	{
		c=getch();
		if(c=='0') break;
	}
	mysql_free_result(&res);
}



void teac::display_one(MYSQL *sock,int tn)
{
	char qbuf[256];
	MYSQL_ROW row ;  // ���һ�в�ѯ������ַ�������
	char a[20],b[20];
	if(tn==1) {strcpy(a,"teacher");strcpy(b,"tea_num"); }
	else if(tn==2) {strcpy(a,"cla"); strcpy(b,"cla_num");}
	else if(tn==3) {strcpy(a,"course");strcpy(b,"cours_num");}
	else {strcpy(a,"cou_cla"); strcpy(b,"r_num");}

	show_head();
	printf("������Ҫ��ѯ��%s��id: ",a);
	char id[20];
	cin>>id;
	sprintf(qbuf,"SELECT * FROM %s where %s  = %s  ; ",a,b,id);//input sql command
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
 	cout<<" the result is: "<<endl<<endl<<endl;
	

	cout<<"------------------------------------------------------------------------------------------------"<<endl;
	while( (row = mysql_fetch_row(&res)) != NULL )	//��ӡÿһ�е�����
	{
		for(int j=0; j<numFields; j++)
		{
			printf("%s=%s  ", column[j],row[j]);
		}
		cout<<endl;
	}	
    cout<<endl<<endl<<endl<<endl<<"# ��Ϣչʾ���� ��0����#"<<endl;
	char c;
	while(1)
	{
		c=getch();
		if(c=='0') break;
	}
	mysql_free_result(&res);
}



void teac::display_one(MYSQL *sock,char t[],char bb[],char aa[])
{
	char qbuf[256];
	MYSQL_ROW row ;  // ���һ�в�ѯ������ַ�������

	sprintf(qbuf,"SELECT * FROM %s where %s = %s; ",t,bb,aa);//input sql command
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


	while( (row = mysql_fetch_row(&res)) != NULL )	//��ӡÿһ�е�����
	{
		for(int j=0; j<numFields; j++)
		{
			printf(" %s\t",row[j]);
		}
		cout<<endl;
	}	

	mysql_free_result(&res);
}



void teac::modify(MYSQL &mysql,MYSQL *sock,int tn)
{
	char qbuf[256];
	show_head();
	
	char a[20],b[20];
	if(tn==1) {strcpy(a,"teacher");strcpy(b,"tea_num");}
	else if (tn==2) {strcpy(a,"cla");strcpy(b,"cla_num");}
	else if(tn==3) {strcpy(a,"course");strcpy(b,"cours_num");}
	else  {strcpy(a,"cou_cla");strcpy(b,"r_num");}

	printf("������Ҫ�޸ĵ�%s��%s:",a,b);
	char id[15];
	cin>>id;
	cout<<"Ҫ�޸������ĸ����ԣ�"<<endl;
	char at[20];
	cin>>at;
	cout<<"����Ϊ��"<<endl;
	char modi[20];
	cin>>modi;

	sprintf(qbuf, "update  %s set %s = '%s' where %s ='%s';",a,at,modi,b,id);
	mysql_query(&mysql, qbuf);

	cout<<"�޸Ľ������޸ĺ�Ľ��Ϊ��\n";
	display_one(sock,a,b,id);

	cal_all_work(mysql,sock);

	cout<<endl<<endl<<endl<<endl<<"# ��Ϣչʾ���� ��0����#"<<endl;
	char c;
	while(1)
	{
		c=getch();
		if(c=='0') break;
	}
}


void teac::cal_all_work(MYSQL mysql,MYSQL *sock)
{
	cal_noc(mysql,sock);
	cal_c_work_time(mysql,sock);
	cal_t_work_time(mysql,sock);
	cout<<"\nwork calculation complete.\n";

}






/*    ����ÿ���γ̵İ༶����    */
void teac::cal_noc(MYSQL mysql,MYSQL *sock)
{

	char qbuf[256];
	MYSQL_ROW row ;  // ���һ�в�ѯ������ַ�������

	sprintf(qbuf,"SELECT cours_num FROM course;");//input sql command
	if(mysql_query(sock,qbuf))
	{
		fprintf(stderr,"Query failed! (%s)",mysql_error(sock));
		exit(1);
	}


	MYSQL_RES res; 
	res = *mysql_store_result(sock);
	unsigned short numFields;

	numFields = mysql_num_fields(&res);	//ͳ�� table �ֶ�
	

	while( (row = mysql_fetch_row(&res)) != NULL )	//��ӡÿһ�е�����
	{
		for(int j=0; j<numFields; j++)
		{
			sprintf(qbuf, "update course set number_of_course = (select count(*) from cou_cla where co_id= '%s' ) where cours_num='%s' ;",row[j],row[j]);
			if(mysql_query(sock,qbuf))
			{
				fprintf(stderr,"Query failed! (%s)",mysql_error(sock));
				exit(1);
			}
		}
	}

}




/*  ����ÿ���γ̵Ĺ���ʱ��  */
void teac::cal_c_work_time(MYSQL mysql,MYSQL *sock)
{
	char qbuf[256];


	sprintf(qbuf, "update course set work_time = theo_time+expo_time ;");
	if(mysql_query(sock,qbuf))
	{
		fprintf(stderr,"Query failed! (%s)",mysql_error(sock));
		exit(1);
	}
	sprintf(qbuf, "update course set work_time =  0*work_time  where number_of_course =0 ;");
	if(mysql_query(sock,qbuf))
	{
		fprintf(stderr,"Query failed! (%s)",mysql_error(sock));
		exit(1);
	}
	sprintf(qbuf, "update course set work_time =  1.0*work_time  where number_of_course =1 ;");
	if(mysql_query(sock,qbuf))
	{
		fprintf(stderr,"Query failed! (%s)",mysql_error(sock));
		exit(1);
	}
	sprintf(qbuf, "update course set work_time =  1.5*work_time  where number_of_course =2 ;");
	if(mysql_query(sock,qbuf))
	{
		fprintf(stderr,"Query failed! (%s)",mysql_error(sock));
		exit(1);
	}
	sprintf(qbuf, "update course set work_time =  2.0*work_time  where number_of_course =3 ;");
	if(mysql_query(sock,qbuf))
	{
		fprintf(stderr,"Query failed! (%s)",mysql_error(sock));
		exit(1);
	}
	sprintf(qbuf, "update course set work_time =  2.5*work_time  where number_of_course >3 ;");
	if(mysql_query(sock,qbuf))
	{
		fprintf(stderr,"Query failed! (%s)",mysql_error(sock));
		exit(1);
	}

}




/*     ����ÿ����ʦ�Ĺ���ʱ��    */
void teac::cal_t_work_time(MYSQL mysql,MYSQL *sock)
{
	char qbuf[256];
	MYSQL_ROW row ;  // ���һ�в�ѯ������ַ�������

	sprintf(qbuf,"SELECT tea_num FROM teacher;");//input sql command
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
	while( (row = mysql_fetch_row(&res)) != NULL )	//��ӡÿһ�е�����
	{
		for(int j=0; j<numFields; j++)
		{
			sprintf(qbuf, "update teacher set teacher.work_time = (select sum(work_time) from course where teacher_id= %s ) where tea_num= %s;",row[j],row[j]);
			if(mysql_query(sock,qbuf))
			{
				fprintf(stderr,"Query failed! (%s)",mysql_error(sock));
				exit(1);
			}
		}
	}
}





