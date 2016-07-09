#include <iostream>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
using namespace std;
int main()
{
	FILE *header=fopen("files/header.h","w");
	FILE *func=fopen("files/func.h","w");
	fclose(header);
	fclose(func);
	char history[100][1000];
	int j=0;
	cout<<"cptr v0.0.1"<<endl<<"Built on gcc version 4.9.3 (Ubuntu 4.9.3-5ubuntu1~14.04)"<<endl<<"Type \"help\", \"credits\" for more information."<<endl;
	while(1)
	{
		cout<<endl<<">>>";
		char input[1000];
		cin.getline(input,sizeof(input));
		int i=0;
		if(strcmp(input,"help")==0)
		{
			cout<<"cnterpreter aims at making testing of syntax for c/c++ easier. It does everything needed in background."<<endl;
			cout<<"You begin with typing single line statements and cnterpreter will execute them for you as if c/c++ was an interpreted language."<<endl;
			cout<<"You can begin with typing 'cout<<\"hello world\"'."<<endl;
			continue;
		}
		if(strcmp(input,"credits")==0)
		{
			cout<<"Build by Subham Rathore"<<endl;
			cout<<"In case you find any bugs, feel free to drop a mail at sbhm94@gmail.com.";
			continue;
		}
		while(input[i]!='\0')
		{
			if(input[i]!=' ')
			{
				break;
			}
			i++;
		}
		if(input[i]=='#')
		{
			FILE *header=fopen("files/header.h","a");
			fputs(input,header);
			fputs("\n",header);
			fclose(header);
		}
		else
		{
			int flag=0;
			int i=0;
			while(input[i]!='\0')
			{
				if(input[i]=='=')
				{
					strcpy(history[j],input);
					j++;
					flag=1;
					break;
				}
				if(input[i]=='+' || input[i]=='-')
				{
					if(input[i+1]==input[i])
					{
						strcpy(history[j],input);
						j++;
						flag=1;
						break;
					}
				}
				i++;
			}
			if(flag==1)
			{
				continue;
			}
			FILE *func=fopen("files/func.h","w");
			fputs("using namespace std;\nvoid func()\n{\n\t",func);
			for(int i=0;i<j;i++)
			{
				fputs(history[i],func);
				fputs("\n",func);
			}
			if(flag==0)
			{
				fputs(input,func);
			}
			fputs("\n}\n",func);
			fclose(func);
			system("g++ files/main.cpp -o files/main.out");
			system("files/main.out");
		}
	}
	return 0;
}