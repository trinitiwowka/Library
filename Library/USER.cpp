#include"USER.h"
#include<fstream>
#include<string>
using namespace std;
bool USER::HaveUser(int ID_user)
{
	int const N=60;
	bool result_serch=0;
	FILE* f1 = fopen("User_databaze.txt", "r");
	fseek( f1 , 0 , SEEK_SET );
	char buf[N];
	do
	{
		fgets(buf,N,f1);
		char* seps={"$"};
		char *token = strtok(buf ,seps);//first word
		while( token != NULL )
		{
			if(ID_user==atoi(token))
			{
				result_serch=1;
				return true;
			}
			token = strtok(NULL, seps );
		}
	}
	while(!feof(f1));	
	fseek( f1 , 0 , SEEK_SET );//на всякий случай вернем указатель на начало файла
	fclose(f1);
	if(!result_serch)
	{
		return false;
	}
}
void USER::AddUser(int new_id)
{
	std::cout<<"Add user:\n";
	class USER
	{
	public:
		void EnterDataOfUser(int id)
		{
			std::cout<<"What you id?:";
	//		int id;
		//	std::cin>>id;
			USER::Id=(id>0&&id<99999)?id:0;

			std::cout<<"Enter you name(no spaces,len<20): ";
			char name[NAMELENGTH];
			std::cin>>name;
			strcpy(USER::FullName,name);

			int HowBook;
			/*cout<<"How many book do you need?";
			cin>>HowBook;*/
			HowBook=0;
			USER::HowManyBook=(HowBook>0)?HowBook:0;

			int id_book;
			/*cout<<"what a number of books?:";
			cin>>id_book;*/
			id_book=0;
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
	}User;

	User.EnterDataOfUser(new_id);
	User.put_user();
}
void USER::AddUser()
{
	std::cout<<"Add user:\n";
	class USER
	{
	public:
		void EnterDataOfUser()
		{
			std::cout<<"What you id?:";
			int id;
			std::cin>>id;
			USER::Id=(id>0&&id<99999)?id:0;

			std::cout<<"Enter you name(no spaces,len<20): ";
			char name[NAMELENGTH];
			std::cin>>name;
			strcpy(USER::FullName,name);

			int HowBook;
			/*cout<<"How many book do you need?";
			cin>>HowBook;*/
			HowBook=0;
			USER::HowManyBook=(HowBook>0)?HowBook:0;

			int id_book;
			/*cout<<"what a number of books?:";
			cin>>id_book;*/
			id_book=0;
			USER::id_book=(id_book>100000&&id_book<999999)?id_book:0;
		}
		void put_user()
		{
			std::ofstream FI;
			FI.open("User_databaze.txt",std::ios::app);//открыт поток FI
			FI<<std::endl<<Id<<"$"<<FullName<<"$"<<HowManyBook<<"$"<<id_book<<"$";
			FI.close();//закрыт поток FI
		
		}
	private:
		int Id;
		char FullName[NAMELENGTH];
		int HowManyBook;
		int id_book;
	}User;

	User.EnterDataOfUser();
	User.put_user();
}
void USER::GetBook(int id_book,int ID_USER)
{
	//function should give a man a book and make two entries in the catalog files,
	//a book is a man and make a note to the user, that he had taken the book.
	//part 1:
	std::ifstream filein("Cat.txt"); //File to read from
    std::ofstream fileout("Cat(tmp).txt"); //Temporary file
	int const N=60;
	bool SerchingResult=0;
	char buf[N];
	memset(buf,0,sizeof(buf));

	string TEMP;
	while(filein>>TEMP)
	{
		char *s = new char[TEMP.size() + 1];
		strcpy(s, TEMP.c_str());
		char *p = strtok(s, "$");
		while (p!=NULL)
		{
			if(atoi(p)==id_book)
			{
				std::cout<<"Book found and added to user:\n";
				char bufer_words[N];
				strcpy(bufer_words,TEMP.c_str());
				char*ss=strtok(bufer_words,"$");
				int i=1;
				while(ss!=NULL)
				{
					if(i==4)
					{
						char* qwe;// int in char*
						char rty[NAMELENGTH];//buffer
						qwe=itoa(ID_USER,rty,10);
						std::cout<<ID_USER<<"\t";
						strcat(buf,qwe);
						strcat(buf,"$");
					}
					else
					{
						std::cout<<ss<<"\t";
						strcat(buf,ss);
						strcat(buf,"$");
					}
					++i;
					ss=strtok(NULL,"$");
				}
				//cout<<endl<<buf<<endl;
				SerchingResult=1;
				fileout<<buf;
				memset(buf,0,sizeof(buf));
				goto nextstring;
			}
			//cout << p << "\t";
			fileout<<TEMP;break;
			nextstring:
			p = strtok(NULL, "$");
		}
		
		fileout<<std::endl;
		delete[] s;
		//cout<<TEMP<<'\n';
		//fileout<<TEMP<<endl;
	}
	filein.close();
	fileout.close();
	ifstream fileinn("Cat(tmp).txt"); //File to read from
    ofstream fileoutt("Cat.txt"); //Temporary file
	string tmp;
	while(fileinn>>tmp)
	{
		fileoutt<<tmp;
		fileoutt<<endl;
	}
	fileinn.close();
	fileoutt.close();
	if(!SerchingResult)//if nothing is found
	{
		cout<<"ERROR book "<<id_book<<" not found!";
exit(99);//book not found
	}
	//part 2:
	//теперь нужно сделать отметку у юзера, что он взял эту книжку
	//start
	ifstream in("User_databaze.txt");
	ofstream out("User_databaze(tmp).txt");
	memset(buf,0,sizeof(buf));//важно!
	while(in>>TEMP)
	{
		char *s = new char[TEMP.size() + 1];
		strcpy(s, TEMP.c_str());
		char *p = strtok(s, "$");
		while (p!=NULL)
		{
			if(atoi(p)==ID_USER)
			{
				char bufer_words[N];
				strcpy(bufer_words,TEMP.c_str());
				char*ss=strtok(bufer_words,"$");
				int i=1;
				while(ss!=NULL)
				{
					char* qwe;//указатель на строку int в char*
					char rty[NAMELENGTH];//буфер
					//cout<<buf<<endl;
					if(i==3)
					{
						int NumberOfBooks=atoi(ss);
						NumberOfBooks++;
						qwe=itoa(NumberOfBooks,rty,10);
						strcat(buf,rty);
						strcat(buf,"$");
						goto end;
					}
					addbook:
					if(i==4)//начиная с 4 лексемы идут записи книг
					{
							qwe=itoa(id_book,rty,10);
							strcat(buf,qwe);
							strcat(buf,"$");
							++i;goto addbook;//добвить запись о новой книге
					}
					else
					{
						strcat(buf,ss);
						strcat(buf,"$");
					}
					end:
					++i;
					ss=strtok(NULL,"$");
				}
				out<<buf;
				memset(buf,0,sizeof(buf));
				goto nextnextstring;
			}
			//cout << p << "\t";
			out<<TEMP;break;
			nextnextstring:
			p = strtok(NULL, "$");
		}
		
		out<<endl;
		delete[] s;
	}
	in.close();
	out.close();
	ifstream file("User_databaze(tmp).txt"); //File to read from
    ofstream outt("User_databaze.txt"); //Temporary file
	while(file>>tmp)
	{
		outt<<tmp;
		outt<<endl;
	}
	file.close();
	outt.close();
}
void USER::ShowAboutUserAll(int ID_user)
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
		char *token = strtok(buf ,seps);//пошук першого слова
		while( token != NULL )
		{
			if(ID_user==atoi(token)&&token!=NULL)//если что-то нашло
			{
				//std::cout<<"\nYou search: "<<ID_user<<"\n";
				while(token!=NULL)
				{
					if(token!=NULL)std::cout<<token<<"\t";
					token = strtok(NULL, seps );
				}
				result_serch=1;
				break;
			}
			else
			{
				break;
			}
			token = strtok(NULL, seps );//пошук наступного слова
		}
		//std::cout<<std::endl;
	}
		
	fseek( f1 , 0 , SEEK_SET );//на всякий случай вернем указатель на начало файла
	fclose(f1);
	if(!result_serch)
	{
		std::cout<<"\nUser "<<ID_user<<" not found\n";
	}
	std::cin.get();
}
void USER::OutBook(int id_book,int ID_USER)
{
	//function should give a man a book and make two entries in the catalog files,
	//a book is a man and make a note to the user, that he had taken the book.
	//part 1:
	std::ifstream filein("Cat.txt"); //File to read from
    std::ofstream fileout("Cat(tmp).txt"); //Temporary file
	int const N=60;
	bool SerchingResult=0;
	char buf[N];
	memset(buf,0,sizeof(buf));

	string TEMP;
	while(filein>>TEMP)
	{
		char *s = new char[TEMP.size() + 1];
		strcpy(s, TEMP.c_str());
		char *p = strtok(s, "$");
		while (p!=NULL)
		{
			if(atoi(p)==id_book)
			{
				std::cout<<"Book found: \n";
				char bufer_words[N];
				strcpy(bufer_words,TEMP.c_str());
				char*ss=strtok(bufer_words,"$");
				int i=1;
				while(ss!=NULL)
				{
					if(i==4)
					{
						//char* qwe;// int in char*
						//char rty[NAMELENGTH];//buffer
						//qwe=itoa(ID_USER,rty,10);
						//std::cout<<ID_USER<<"\t";
						//strcat(buf,qwe);
						strcat(buf,"0$");
					}
					else
					{
						std::cout<<ss<<"\t";
						strcat(buf,ss);
						strcat(buf,"$");
					}
					++i;
					ss=strtok(NULL,"$");
				}
				//cout<<endl<<buf<<endl;
				SerchingResult=1;
				fileout<<buf;
				memset(buf,0,sizeof(buf));
				goto nextstring;
			}
			//cout << p << "\t";
			fileout<<TEMP;break;
			nextstring:
			p = strtok(NULL, "$");
		}
		
		fileout<<std::endl;
		delete[] s;
		//cout<<TEMP<<'\n';
		//fileout<<TEMP<<endl;
	}
	filein.close();
	fileout.close();
	ifstream fileinn("Cat(tmp).txt"); //File to read from
    ofstream fileoutt("Cat.txt"); //Temporary file
	string tmp;
	while(fileinn>>tmp)
	{
		fileoutt<<tmp;
		fileoutt<<endl;
	}
	fileinn.close();
	fileoutt.close();
	if(!SerchingResult)//if nothing is found
	{
		cout<<"ERROR book "<<id_book<<" not found!";
exit(99);//book not found
	}

	//part 2:
	//dell book at the user
	//start
	ifstream in("User_databaze.txt");
	ofstream out("User_databaze(tmp).txt");
	memset(buf,0,sizeof(buf));//важно!
	while(in>>TEMP)
	{
		char *s = new char[TEMP.size() + 1];
		strcpy(s, TEMP.c_str());
		char *p = strtok(s, "$");
		while (p!=NULL)
		{
			if(atoi(p)==ID_USER)
			{
				char bufer_words[N];
				strcpy(bufer_words,TEMP.c_str());
				char*ss=strtok(bufer_words,"$");
				int i=1;
				while(ss!=NULL)
				{
					char* qwe;//указатель на строку int в char*
					char rty[NAMELENGTH];//буфер
					//cout<<buf<<endl;
					if(i==3)
					{
						int NumberOfBooks=atoi(ss);
						NumberOfBooks--;
						qwe=itoa(NumberOfBooks,rty,10);
						strcat(buf,rty);
						strcat(buf,"$");
						goto end;
					}
					if(i>=4&&atoi(ss)==id_book)//начиная с 4 лексемы идут записи книг
					{
							
							++i;//добвить запись о новой книге
					}
					else
					{
						strcat(buf,ss);
						strcat(buf,"$");
					}
					end:
					++i;
					ss=strtok(NULL,"$");

				}
				out<<buf;
				memset(buf,0,sizeof(buf));
				goto nextnextstring;
			}
			//cout << p << "\t";
			out<<TEMP;break;
			nextnextstring:
			p = strtok(NULL, "$");
		}
		
		out<<endl;
		delete[] s;
	}
	in.close();
	out.close();
	ifstream file("User_databaze(tmp).txt"); //File to read from
    ofstream outt("User_databaze.txt"); //Temporary file
	while(file>>tmp)
	{
		outt<<tmp;
		outt<<endl;
	}
	file.close();
	outt.close();
}