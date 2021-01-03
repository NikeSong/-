#ifndef tea_h
#define tea_h

#include <iostream>
#include <cstdlib>
#include <winsock.h>
#include <mysql.h>
#pragma comment(lib,"libmysql.lib")


class system
{
public:
	void insert_teach_data(string tea_num,strng name,string gender,string title,string course,string clas,int cla_num,double the_time,double exp_time);
	void display_teach_data();
	void modify_teach_data();
	void delete_teach_data();
	void calcutate_number();
}



#endif