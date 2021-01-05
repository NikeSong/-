#ifndef tea_h
#define tea_h

#include <conio.h>
#include <iostream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <winsock.h>
#include <mysql.h>
#include <cstdio>
#pragma comment(lib,"libmysql.lib")
using namespace std;


class teac
{
public:
	void insert(MYSQL &mysql,MYSQL *sock,int tn);
	void deletes(MYSQL &mysql,MYSQL *sock,int tn);
	void modify(MYSQL &mysql,MYSQL *sock,int tn);
	void displays(MYSQL *sock);
	void display_one(MYSQL *sock,int tn);
	void display_one(MYSQL *sock,char t[],char b[],char aa[]);

	void show_head();


	void cal_noc(MYSQL mysql,MYSQL *sock);
	void cal_c_work_time(MYSQL mysql,MYSQL *sock);
	void cal_t_work_time(MYSQL mysql,MYSQL *sock);
	void cal_all_work(MYSQL mysql,MYSQL *sock);
};







#endif