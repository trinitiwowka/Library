#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#define NAMELENGTH 30


void OutstandingBooks(int id_book,int ID_USER);

void OutstandingBooks(int id_book,int ID_USER)
{
	//function should give a man a book and make two entries in the catalog files,
	//a book is a man and make a note to the user, that he had taken the book.
	//part 1:
	ifstream filein("Cat.txt"); //File to read from
    ofstream fileout("Cat(tmp).txt"); //Temporary file
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
				cout<<"Book found and added to user:\n";
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
						cout<<ID_USER<<"\t";
						strcat(buf,qwe);
						strcat(buf,"$");
					}
					else
					{
						cout<<ss<<"\t";
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
		
		fileout<<endl;
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
					if(i==4)//начиная с четвертой лексемы идут записи книг
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