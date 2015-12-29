#include <iostream>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
using namespace std;

class Config
{
private:
	string fileName;
public:
	char ip[32];
	char dbName[32];
	char uid[32];
	char password[32];
public:
	Config();
	~Config();
	bool GetConfigFileName();
	bool ReadConfig();
};
