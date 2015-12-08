#include"ADMIN.h"
void ADMIN::ShowDataUsers()
{
	int const N=60;
	FILE* f1 = fopen("User_databaze.txt", "r");
	char buf[N];
	
	//show about hader file
	while(!feof(f1))
	{
		fgets(buf,N,f1);
		char* seps={"$"};
		char *token = strtok(buf ,seps);//пошук першого слова

		while( token != NULL )
		{
			if(token!=NULL)
			std::cout<<token<<"\t";
			token = strtok(NULL, seps );//пошук наступного слова
		}
		std::cout<<std::endl;
	}
}