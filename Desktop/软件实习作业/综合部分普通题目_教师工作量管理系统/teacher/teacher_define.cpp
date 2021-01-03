#include"teacher_h.h"


/*教师类的成员函数*/


void teac::head_dis()
{
	cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl<<endl;
	cout<<"                                教  师  管  理  系  统                           "<<endl<<endl;
	cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
	cout<<endl;
}




/*      增      */
void teac::insert_teach_data(MYSQL &mysql)
{
	while(1)
	{
		head_dis();
		char c;
		char qbuf[256];
		cout<<"请依次输入教师号，教师姓名，性别，职称，课程"<<endl;
		char tea_num_s[50],name_s[50],gender_s[50],title_s[50],course_s[50];
		cin>>tea_num_s>>name_s>>gender_s>>title_s>>course_s;
		sprintf(qbuf, "insert into teacher (tea_num,name,gender,title,cors) values ('%s','%s','%s','%s','%s');",tea_num_s,name_s,gender_s,title_s,course_s);
		mysql_query(&mysql,qbuf);
		cout<<"已插入-   "<<tea_num_s<<' '<<name_s<<' '<<gender_s<<' '<<title_s<<' '<<course_s<<endl;
		cout<<"按0以退出，按1继续输入"<<endl;
		c=getch();
		if(c=='0') break;
	}
}





/*      查     */
void teac::display_teach_data(MYSQL *sock)
{
	char qbuf[256];
	MYSQL_ROW row ;  // 存放一行查询结果的字符串数组
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


	numFields = mysql_num_fields(&res);	//统计 table 字段
	
	for(int i = 0; i < numFields; ++i)	//保存字段
	{
		strcpy(column[i], mysql_fetch_field(&res)->name);
		// printf("%s\n", column[i]);
	}
 	cout<<" the result is: "<<endl;

	while( (row = mysql_fetch_row(&res)) != NULL )	//打印每一行的内容
	{
		for(int j=0; j<numFields; j++)
		{
			printf("%s = %s\t", column[j], row[j]);
		}
		cout<<endl;
	}

	
    cout<<endl<<endl<<endl<<endl<<"# 教师信息展示结束 按0返回#"<<endl;
	char c;
	while(1)
	{
		c=getch();
		if(c=='0') break;
	}
	mysql_free_result(&res);
}



/*     删    */
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
		
		cout<<endl<<"# 教师信息删除结束 按0返回 按1继续#"<<endl;
		char c;
		c=getch();
		if(c=='0') break;
		else continue;
	}

}



void teac::calculate_number()
{


}







/*   课程类的成员函数  */

/*   增  */
void cour::insert_cour_data(MYSQL &mysql)
{
	while(1)
	{
		teac a;
		a.head_dis();
		char c;
		char qbuf[256];
		cout<<"请依次输入课程号，课程名称、理论学时，实验学时"<<endl;
		char cour_num_s[50],cour_name_s[50];
		double theo_time_s,exp_time_s;
		cin>>cour_num_s>>cour_name_s>>theo_time_s>>exp_time_s;
		double all_time_s=theo_time_s+exp_time_s;
		sprintf(qbuf, "insert into course (cla_num,cla_name,theo_time,expo_time,all_time) values ('%s','%s','%lf','%lf','%lf');",cour_num_s,cour_name_s,theo_time_s,exp_time_s,all_time_s);
		mysql_query(&mysql,qbuf);
		cout<<"已插入-   "<<cour_num_s<<' '<<cour_name_s<<' '<<theo_time_s<<' '<<exp_time_s<<endl;
		cout<<"按0以退出，按1继续输入"<<endl;
		c=getch();
		if(c=='0') break;
	}
}



/*  查  */
void cour::display_cour_data(MYSQL *sock)
{
	char qbuf[256];
	MYSQL_ROW row ;  // 存放一行查询结果的字符串数组
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


	numFields = mysql_num_fields(&res);	//统计 table 字段

	for(int i = 0; i < numFields; ++i)	//保存字段
	{
		strcpy(column[i], mysql_fetch_field(&res)->name);
		// printf("%s\n", column[i]);
	}
 	cout<<" the result is: "<<endl;

	while( (row = mysql_fetch_row(&res)) != NULL )	//打印每一行的内容
	{
		for(int j=0; j<numFields; j++)
		{
			printf("%s = %s\t", column[j], row[j]);
		}
		cout<<endl;
	}

	
    cout<<endl<<endl<<endl<<endl<<"#  课程信息展示结束 按0返回#"<<endl;
	char c;
	while(1)
	{
		c=getch();
		if(c=='0') break;
	}
	mysql_free_result(&res);
}




/*    删   */
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
		
		cout<<endl<<"# 课程信息删除结束 按0返回 按1继续#"<<endl;
		char c;
		c=getch();
		if(c=='0') break;
		else continue;
	}

}



/*班级类的增删查*/



void cla::insert_cla_data(MYSQL &mysql)
{
	while(1)
	{
		teac a;
		a.head_dis();
		char c;
		char qbuf[256];
		cout<<"请依次输入班级号，班级名"<<endl;
		char cla_num_s[50],cla_name_s[50];
		cin>>cla_num_s>>cla_name_s;
		sprintf(qbuf, "insert into cla (cla_num,cla_name) values ('%s','%s');",cla_num_s,cla_name_s);
		mysql_query(&mysql,qbuf);
		cout<<"已插入-   "<<cla_num_s<<' '<<cla_name_s<<endl;
		cout<<"按0以退出，按1继续输入"<<endl;
		c=getch();
		if(c=='0') break;
	}
}




void cla::display_cla_data(MYSQL *sock)
{
	char qbuf[256];
	MYSQL_ROW row ;  // 存放一行查询结果的字符串数组
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


	numFields = mysql_num_fields(&res);	//统计 table 字段
	
	for(int i = 0; i < numFields; ++i)	//保存字段
	{
		strcpy(column[i], mysql_fetch_field(&res)->name);
		// printf("%s\n", column[i]);
	}
 	cout<<" the result is: "<<endl;

	while( (row = mysql_fetch_row(&res)) != NULL )	//打印每一行的内容
	{
		for(int j=0; j<numFields; j++)
		{
			printf("%s = %s\t", column[j], row[j]);
		}
		cout<<endl;
	}
    cout<<endl<<endl<<endl<<endl<<"#  班级信息展示结束 按0返回#"<<endl;
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
		
		cout<<endl<<"# 班级信息删除结束 按0返回 按1继续#"<<endl;
		char c;
		c=getch();
		if(c=='0') break;
		else continue;
	}

}

