#include "config.h"
#include "sqlserver.h"

int main(int argc, char** argv)
{
	Config *config=new Config();
	if(!config->ReadConfig())
	{
		delete config;
		return -1;
	}

	SqlClient *client=new SqlClient();
	if(client->Open(config->ip,config->dbName,config->uid,config->password)==-1)
	{
		delete config;
		return -1;
	}
	delete config;
	string szSql;
	cout<<"please enter executesql:"<<endl;
	getline(cin,szSql);
	client->ExecuteNonQuery(szSql.c_str());

	char szID[20]={0};  
	char szName[80]={0};  
	cout<<"please enter querysql:"<<endl;
	getline(cin,szSql);
	int recode=client->ExecuteQuery(szSql.c_str());
        if (recode == 1)
	{  
		dbbind(client->dbprocess, 1, CHARBIND, (DBINT)0, (BYTE*)szID);  
		dbbind(client->dbprocess, 2, CHARBIND, (DBCHAR)0, (BYTE*)szName);  
		cout<<"ID\tName"<<endl; 
		while (dbnextrow(client->dbprocess) != NO_MORE_ROWS)
		{                          
			cout<<szID<<"\t"; 
			cout<<szName<<endl; 
		}  
        } 
 
	client->Close();

	delete client;

}
