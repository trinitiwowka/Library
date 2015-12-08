#include"BOOK.h"
#include<fstream>
#define NAMELENGTH 30
BOOK::BOOK()
{
	
}
void BOOK::show_about_book(int ID_book)
{
int const N=60;
	FILE* f1 = fopen("Cat.txt", "r");
	fseek( f1 , 0 , SEEK_SET );
	char buf[N];
	bool Serch_Result=0;
	do
	{
		fgets(buf,N,f1);
		char* seps={"$"};
		char *token = strtok(buf ,seps);//пошук першого слова
		while( token != NULL )
		{
			if(ID_book==atoi(token))//если что-то нашло
			{
				std::cout<<"You search: "<<ID_book<<"\n";
				while(token!=NULL){std::cout<<token<<"\t";token = strtok(NULL, seps );}
				Serch_Result=1;
				break;
			}
			token = strtok(NULL, seps );//пошук наступного слова
		}
		//std::cout<<std::endl;
	}
	while(!feof(f1));
	if(!Serch_Result)
	{std::cout<<"book not found\n";}
}
void BOOK::MakeBazaBook()
{

	struct library
	{
		int num;//100000-999999
		char AutorBook[NAMELENGTH];
		char NameBook[NAMELENGTH];
		int Nalichie; //0/1
		int WhoCarry;//00000
		library::library()
		{
			num=100000;
			memset(AutorBook, 0, sizeof(AutorBook));
			memset(NameBook, 0, sizeof(NameBook));
			Nalichie=0;
			WhoCarry=00000;
		}
	}lib;

	int const N=70;
	char buf[N]={"\0"};
	FILE *file1 =fopen("Cat.txt","w");
	for(int i=0;i<99;++i)//создание рендомной базы
	{
		lib.num=100000+i;
		strcpy(lib.AutorBook,"AutorBook");
		strcpy(lib.NameBook,"NameBook");//"NameBook"+i error
		lib.Nalichie=0;
		lib.WhoCarry=00000;
		fprintf(file1,"%d$%s%d$%s%d$%d$\n",lib.num,lib.AutorBook,i,lib.NameBook,i,lib.Nalichie);		
	}
	fclose(file1);
}
void BOOK::MakeBazaUser()
{
	int const N=60;
	char buf[N];
	class USER
	{
	public:
		USER()
		{
			Id=0;
			memset(FullName,'_',sizeof(char)*NAMELENGTH);
			HowManyBook=0;
			id_book=0;
		}
		USER(int id,char name[NAMELENGTH],int HowBook,int id_book)
		{
			USER::Id=(id>0&&id<99999)?id:0;
			strcpy(USER::FullName,name);
			USER::HowManyBook=(HowBook>0)?HowBook:0;
			USER::id_book=(id_book>100000&&id_book<999999)?id_book:0;
		}
		void put_user()
		{
			std::ofstream FI;
			FI.open("User_databaze.txt",std::ios::app);//открыт поток FI
			FI<<Id<<"$"<<FullName<<"$"<<HowManyBook<<"$"<<id_book<<"$"<<std::endl;
			FI.close();//закрыт поток FI
		}
	private:
		int Id;
		char FullName[NAMELENGTH];
		int HowManyBook;
		int id_book;
	};

	for(int i=0;i<10;++i)
	{
		USER test;
		test.put_user();
	}
}