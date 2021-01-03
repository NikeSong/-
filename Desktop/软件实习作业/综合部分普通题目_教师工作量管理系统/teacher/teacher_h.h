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
	void insert_teach_data(MYSQL &mysql);
	void display_teach_data(MYSQL *sock);
	void delete_teach_data(MYSQL &mysql,MYSQL *sock);
	void calculate_number();
	void teac::head_dis();
};


class cour
{
public:
	void insert_cour_data(MYSQL &mysql);
	void display_cour_data(MYSQL *sock);
	void delete_cour_data(MYSQL &mysql,MYSQL *sock);
};

class cla
{
public:
	void insert_cla_data(MYSQL &mysql);
	void display_cla_data(MYSQL *sock);
	void delete_cla_data(MYSQL &mysql,MYSQL *sock);
};





#endif