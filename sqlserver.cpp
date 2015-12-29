#include <sybdb.h>
#include "sqlserver.h"

SqlClient::SqlClient()
{

}

SqlClient::~SqlClient()
{

}

int SqlClient::Open(const char* server,const char* dbName,const char* uid,const char *password)
{

	cout<<"connecting sql server......"<<endl;
	dbinit();	//初始化db-library  
	LOGINREC *loginrec = dblogin();  
        DBSETLUSER(loginrec, uid);         
        DBSETLPWD(loginrec, password);  
        this->dbprocess = dbopen(loginrec, server);	//连接数据库 
	if(dbprocess==FAIL)
	{
		cout<<"connect sql server failed!"<<endl;
		return -1;
	}
	cout<<"connect sql server success!"<<endl;
	if(dbuse(dbprocess, dbName) == FAIL) 
	{ 
		cout<<"connect database failed!"<<endl;
		return -1;
	}
	cout<<"connect database success!"<<endl;
	return 1;
}

void SqlClient::Close()
{
        //关闭数据库连接  
	dbclose(this->dbprocess);  
}

int SqlClient::ExecuteNonQuery(const char* sql)
{
	RETCODE recode;
	recode=dbcmd(dbprocess, sql);
	if(recode==FAIL)
	{
		return -1;
	}
	recode=dbsqlexec(dbprocess);
	cout<<sql<<"-->"<<recode<<endl;
	return recode==SUCCEED?1:0;
}

int SqlClient::ExecuteQuery(const char* sql)
{
	if(this->ExecuteNonQuery(sql)==1)
	{
		RETCODE recode=dbresults(dbprocess);
		return recode==SUCCEED?1:0;
	}
	else
	{
		return -1;
	}
}
