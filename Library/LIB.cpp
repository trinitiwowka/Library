#include"LIB.h"
void LIB::ShowCatalog()
{	
	int const N=60;
	FILE* f1 = fopen("Cat.txt", "r");
	char buf[N];
	
	//show about hader file
	while(!feof(f1))
	{
		fgets(buf,N,f1);
		char* seps={"$"};
		char *token = strtok(buf,seps);//����� ������� �����
		while(token!=NULL)
		{
			if(token!=NULL)
			//std::cout<<token<<"\t";
			token = strtok(NULL, seps );//����� ���������� �����	
		}
		std::cout<<std::endl;
	}
	FILE* f2 = fopen("Cat(backup).txt", "w");
	fseek( f1 , 0 , SEEK_SET );
	while(!feof(f1))
	{
		fgets(buf, N,f1);
		if(!feof(f1))fputs(buf, f2);
	}
	fseek( f1 , 0 , SEEK_SET );
	fclose(f1);
	fclose(f2);
	std::cin.get();
}
void LIB::User_Serch(int ID_user)
{
	int const N=60;
	bool result_serch=0;
	FILE* f1 = fopen("User_databaze.txt", "r");
	fseek( f1 , 0 , SEEK_SET );
	char buf[N];
	while(!feof(f1))
	{
		fgets(buf,N,f1);
		char* seps={"$"};
		char *token = strtok(buf ,seps);//����� ������� �����
		while( token != NULL )
		{
			if(ID_user==atoi(token)&&token!=NULL)//���� ���-�� �����
			{
				//std::cout<<"\nYou search: "<<ID_user<<"\n";
				while(token!=NULL)
				{
					if(token!=NULL){std::cout<<token<<"\t";}
					token = strtok(NULL, seps );
				}
				result_serch=1;
				break;
			}
			else
			{
				break;
			}
			token = strtok(NULL, seps );//����� ���������� �����
		}
	}
	
	fseek( f1 , 0 , SEEK_SET );//�� ������ ������ ������ ��������� �� ������ �����
	fclose(f1);
	if(!result_serch)
	{
		std::cout<<"\nUser "<<ID_user<<" not found\n";
	}
	std::cin.get();
}
int LIB::count_client=0;
LIB::LIB()
{
	count_client++;
}
LIB::~LIB()
{
	count_client--;
}