#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int checkstring(string str)
{
	int count,i;
	if(str[0]==0)
	{
		return -1;
	}
	for(i=0;i<str.length();i++)
	{
		if(isalpha(str[i]) || isspace(str[i]) && str[0]!= ' ' )
		{
			count=0;
		}
		else
		{
			count=1;
			break;
		}
	}
	
	if(count==0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
