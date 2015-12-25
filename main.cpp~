#include <string.h>
#include <stdio.h>
#include "sqlserver.h"

int main(int argc, char** argv)
{
        char szServer[32] = {0};
	char szDBName[32] = {0};
	char szUID[32] = {0};  
        char szPassword[32] = {0}; 
	cout<<"please enter server:port :"<<endl;
	cin>>szServer;
	cout<<"please enter dbname:"<<endl;
	cin>>szDBName;
	cout<<"please enter uid:"<<endl;
	cin>>szUID;
	cout<<"please enter password:"<<endl;
	cin>>szPassword;
	SqlClient *client=new SqlClient();
	if(client->Open(szServer,szDBName,szUID,szPassword)==-1)
	{
		return -1;
	}

	char szSql[1024]={0};
	cout<<"please enter executesql:"<<endl;
	cin>>szSql;
	client->ExecuteNonQuery(szSql);

	char szID[20]={0};  
	char szName[80]={0};  
	cout<<"please enter querysql:"<<endl;
	scanf("%s",szSql);
	int recode=client->ExecuteQuery(szSql);
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
