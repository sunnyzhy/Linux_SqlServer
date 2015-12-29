#include "config.h"

Config::Config()
{

}

Config::~Config()
{

}

bool Config::GetConfigFileName()
{
        this->fileName.clear() ;  
        char szWorkDir[256] = {0} ;  
        if(!getcwd(szWorkDir, 260))  
        {  
            return false ;  
        }  
      
        this->fileName = szWorkDir ;  
        this->fileName.append("/") ;  
        this->fileName.append("db.conf") ;  
      
        return true ;  
}

bool Config::ReadConfig()
{
	cout<<"reading config......"<<endl;
	if(!GetConfigFileName())
	{
		cout<<"read config failed!"<<endl;
		return false;
	}
	FILE *fp;
	char *line=NULL;
	size_t len;
	ssize_t read;
	fp = fopen(this->fileName.c_str(), "r");
	if(fp==NULL)
	{
		cout<<"open file"<<endl;
		return false;
	}
	int n=0;
	while ((read = getline(&line, &len, fp)) != -1)
	{
		string s(line,read);
		if(s.find("=",0)==-1)
		{
			continue;
		}
		string temp=s.substr(s.find("=",0)+1);
		switch(n)
		{
			case 0:
				strcpy(this->ip,temp.substr(0,temp.length()-1).c_str()); 
				break;
			case 1:
				strcpy(this->dbName,temp.substr(0,temp.length()-1).c_str()); 
				break;
			case 2:
				strcpy(this->uid,temp.substr(0,temp.length()-1).c_str()); 
				break;
			case 3:
				strcpy(this->password,temp.substr(0,temp.length()-1).c_str()); 
				break;
		}
		n++;
	}
	fclose(fp);
	cout<<"read config success!"<<endl;
	return true;
}
