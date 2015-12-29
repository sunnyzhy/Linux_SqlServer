#include <iostream>
#include <sybdb.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
using namespace std;

class SqlClient
{
public:
	DBPROCESS *dbprocess;
public:
	SqlClient();
	~SqlClient();
	int Open(const char* server,const char* dbName,const char* uid,const char *password);
	void Close();
	int ExecuteNonQuery(const char* sql);
	int ExecuteQuery(const char* sql);
};
