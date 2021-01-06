#include"teacher_h.h"


void teac::show_head()
{
	cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl<<endl;
	cout<<"                                教  师  管  理  系  统                           "<<endl<<endl;
	cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
	cout<<endl;
}




/*      增      */
void teac::insert(MYSQL &mysql,MYSQL *sock,int tn)
{
	while(1)
	{
		show_head();
		
		char qbuf[256];
		
		switch(tn)
		{
		case 1:{
				cout<<"请依次输入教师号，教师姓名，性别，职称"<<endl;
				char tea_num_s[50],name_s[50],gender_s[50],title_s[50];
				cin>>tea_num_s>>name_s>>gender_s>>title_s;
				sprintf(qbuf, "insert into teacher (tea_num,name,gender,title,work_time) values ('%s','%s','%s','%s',0);",tea_num_s,name_s,gender_s,title_s);
				mysql_query(&mysql,qbuf);
				cout<<"已插入-   "<<tea_num_s<<' '<<name_s<<' '<<gender_s<<' '<<title_s<<' '<<endl;
				break;
			   }
		case 2:{
				cout<<"请依次输入班级号，班级名"<<endl;
				char cla_num_s[50],cla_name_s[50];
				cin>>cla_num_s>>cla_name_s;
				sprintf(qbuf, "insert into cla (cla_num,cla_name) values ('%s','%s');",cla_num_s,cla_name_s);
				mysql_query(&mysql,qbuf);
				cout<<"已插入-   "<<cla_num_s<<' '<<cla_name_s<<endl;
				break;
			   }
		case 3:{
				
				cout<<"请依次输入课程号、课程名称、理论学时、实验学时、授课教师号"<<endl;
				char cour_num_s[50],cour_name_s[50];
				double theo_time_s,exp_time_s;
				char te_nu[50];
				cin>>cour_num_s>>cour_name_s>>theo_time_s>>exp_time_s>>te_nu;
				double all_time_s=theo_time_s+exp_time_s;
				sprintf(qbuf, "insert into course values ('%s','%s',%lf,%lf,0,'%s',%lf);",cour_num_s,cour_name_s,theo_time_s,exp_time_s,te_nu,all_time_s);
				mysql_query(&mysql,qbuf);
				cout<<"已插入-   "<<cour_num_s<<' '<<cour_name_s<<' '<<theo_time_s<<' '<<exp_time_s<<endl;
			    break;
			   }
		case 4:{
				MYSQL_ROW row ;  
			
				sprintf(qbuf,"SELECT count(*) FROM cou_cla;");//input sql command
				mysql_query(&mysql,qbuf);
				MYSQL_RES res; 
				res = *mysql_store_result(sock);
				unsigned short numFields;
				numFields = mysql_num_fields(&res);	//统计 table 字段
				row = mysql_fetch_row(&res);	//打印每一行的内容
				cout<<"请依次输入信息号、选课班级号，要选的课程号"<<endl;
				int nu;
				char cla_id_s[50],cours_id_s[50];
				cin>>nu>>cla_id_s>>cours_id_s;
				sprintf(qbuf, "insert into cou_cla (r_num,cl_id,co_id) values ( %d,'%s','%s');",nu,cla_id_s,cours_id_s);
				mysql_query(&mysql,qbuf);
				cout<<"已插入-   "<<cla_id_s<<' '<<cours_id_s<<endl;
				break;
			   }
		}
		
		cal_all_work(mysql,sock);
		

		cout<<"按0以退出，按1继续输入"<<endl;
		
		char c=getch();
		if(c=='0') break;
	}
}


/*     删    */
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
		cout<<endl<<"# 信息删除结束 按0返回 按1继续#"<<endl;
		char c;
		c=getch();
		if(c=='0') break;
		else continue;
	}

}



/*      查     */
void teac::displays(MYSQL *sock)
{
	show_head();
	char qbuf[256];
	MYSQL_ROW row ;  // 存放一行查询结果的字符串数组

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


	numFields = mysql_num_fields(&res);	//统计 table 字段
	
	for(int i = 0; i < numFields; ++i)	//保存字段
	{
		strcpy(column[i], mysql_fetch_field(&res)->name);
		// printf("%s\n", column[i]);
	}
 	cout<<" the result is: "<<endl<<endl<<endl;
	
	printf("%11s%11s%11s%11s%11s%10s%11s%11s%11s%11s%11s%11s\n","教师号","姓名","性别","职称","工作量","课程号","课程名","理论","实践","班级数","教师号","课程工作量");
	cout<<"-------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	while( (row = mysql_fetch_row(&res)) != NULL )	//打印每一行的内容
	{
		for(int j=0; j<numFields; j++)
		{
			printf("%11s",  row[j]);
		}
		cout<<endl;
	}	
    cout<<endl<<endl<<endl<<endl<<"# 信息展示结束 按0返回#"<<endl;
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
	MYSQL_ROW row ;  // 存放一行查询结果的字符串数组
	char a[20],b[20];
	if(tn==1) {strcpy(a,"teacher");strcpy(b,"tea_num"); }
	else if(tn==2) {strcpy(a,"cla"); strcpy(b,"cla_num");}
	else if(tn==3) {strcpy(a,"course");strcpy(b,"cours_num");}
	else {strcpy(a,"cou_cla"); strcpy(b,"r_num");}

	show_head();
	printf("请输入要查询的%s的id: ",a);
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


	numFields = mysql_num_fields(&res);	//统计 table 字段
	
	for(int i = 0; i < numFields; ++i)	//保存字段
	{
		strcpy(column[i], mysql_fetch_field(&res)->name);
		// printf("%s\n", column[i]);
	}
 	cout<<" the result is: "<<endl<<endl<<endl;
	

	cout<<"------------------------------------------------------------------------------------------------"<<endl;
	while( (row = mysql_fetch_row(&res)) != NULL )	//打印每一行的内容
	{
		for(int j=0; j<numFields; j++)
		{
			printf("%s=%s  ", column[j],row[j]);
		}
		cout<<endl;
	}	
    cout<<endl<<endl<<endl<<endl<<"# 信息展示结束 按0返回#"<<endl;
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
	MYSQL_ROW row ;  // 存放一行查询结果的字符串数组

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


	numFields = mysql_num_fields(&res);	//统计 table 字段
	
	for(int i = 0; i < numFields; ++i)	//保存字段
	{
		strcpy(column[i], mysql_fetch_field(&res)->name);
		// printf("%s\n", column[i]);
	}


	while( (row = mysql_fetch_row(&res)) != NULL )	//打印每一行的内容
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

	printf("请输入要修改的%s的%s:",a,b);
	char id[15];
	cin>>id;
	cout<<"要修改他的哪个属性？"<<endl;
	char at[20];
	cin>>at;
	cout<<"更改为？"<<endl;
	char modi[20];
	cin>>modi;

	sprintf(qbuf, "update  %s set %s = '%s' where %s ='%s';",a,at,modi,b,id);
	mysql_query(&mysql, qbuf);

	cout<<"修改结束，修改后的结果为：\n";
	display_one(sock,a,b,id);

	cal_all_work(mysql,sock);

	cout<<endl<<endl<<endl<<endl<<"# 信息展示结束 按0返回#"<<endl;
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






/*    更新每个课程的班级数量    */
void teac::cal_noc(MYSQL mysql,MYSQL *sock)
{

	char qbuf[256];
	MYSQL_ROW row ;  // 存放一行查询结果的字符串数组

	sprintf(qbuf,"SELECT cours_num FROM course;");//input sql command
	if(mysql_query(sock,qbuf))
	{
		fprintf(stderr,"Query failed! (%s)",mysql_error(sock));
		exit(1);
	}


	MYSQL_RES res; 
	res = *mysql_store_result(sock);
	unsigned short numFields;

	numFields = mysql_num_fields(&res);	//统计 table 字段
	

	while( (row = mysql_fetch_row(&res)) != NULL )	//打印每一行的内容
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




/*  更新每个课程的工作时间  */
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




/*     更新每个老师的工作时间    */
void teac::cal_t_work_time(MYSQL mysql,MYSQL *sock)
{
	char qbuf[256];
	MYSQL_ROW row ;  // 存放一行查询结果的字符串数组

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


	numFields = mysql_num_fields(&res);	//统计 table 字段
	
	for(int i = 0; i < numFields; ++i)	//保存字段
	{
		strcpy(column[i], mysql_fetch_field(&res)->name);
		// printf("%s\n", column[i]);
	}
	while( (row = mysql_fetch_row(&res)) != NULL )	//打印每一行的内容
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





