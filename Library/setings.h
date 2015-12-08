#include<iostream>
#define BUF 20
void menu()
{
LIB national_bibli;
	std::cout<<"Hallo (^_^)\n";
	bool finish=0;
	while(!finish)
	{
		std::cout<<"\nWhat do we do?\n";
		std::cout<<"1:add new user. "<<"2:show catalog. "<<" 3:log on(enter id). "<<"4:serch user. "<<"5:serch book "<<"9:exit."<<std::endl;
		char option[BUF];
		std::cin>>option;
		switch(atoi(option))
		{
		case 1:
			{
				national_bibli.user.AddUser();
				break;
			}
		case 2:
			{
				national_bibli.ShowCatalog();
				break;
			}
		case 3:
			{
				std::cout<<" What you id? ";
				int id;
				do
				{
					std::cin>>id;
					if(!(id>=0&&id<99999))
					std::cout<<"incorrect id try agan";
				}
				while(!(id>=0&&id<99999));
				if(national_bibli.user.HaveUser(id))
				{
					switch(id)
					{
					case 0:
						{
							std::cout<<"Hallo Admin!!!\n";
							bool finish_admin=0;
							while(!finish_admin)
							{
								std::cout<<"What do we do?\n";
								std::cout<<"1:Show data user 2:Show Catalog 9:exit menu"<<std::endl;
								char case_admin[BUF];
								std::cin>>case_admin;
								switch(atoi(case_admin))
								{
								case 1:
									{
										national_bibli.admin.ShowDataUsers();
										break;
									}
								case 2:
									{
										national_bibli.ShowCatalog();
										break;
									}
								case 9:
									{
										finish_admin=1;
										break;
									}
								default:
									{
										std::cout<<"default";
										break;
									}
								}
							}
							std::cout<<"out of menu admin\n";
							break;
						}
					default:/*all user except admin*/
						{
							std::cout<<"Hallo User!!!\n";
							bool finish_user=0;
							while(!finish_user)
							{
								std::cout<<"\nWhat do we do?\n";
								std::cout<<"1:Get book. 2:Show about me. 3:return the book. 9:exit menu"<<std::endl;
								char case_user[BUF];
								std::cin>>case_user;
								switch(atoi(case_user))
								{
								case 1:
									{
										std::cout<<"Enter id book(>100000):\n";
										char cash_id_book[BUF];
										do
										{
											std::cin>>cash_id_book;
											if(!(atoi(cash_id_book)>100000&&atoi(cash_id_book)<999999))
												std::cout<<"Incorrect id book\n";
										}
										while(!(atoi(cash_id_book)>100000&&atoi(cash_id_book)<999999));
										int id_book=atoi(cash_id_book);
										national_bibli.user.GetBook(id_book,id);
										break;
									}
								case 2:
									{
										national_bibli.user.ShowAboutUserAll(id);
										break;
									}
								case 3:
									{
										std::cout<<"Enter id book for return(>100000):\n";
										char cash_id_book[BUF];
										do
										{
											std::cin>>cash_id_book;
											if(!(atoi(cash_id_book)>100000&&atoi(cash_id_book)<999999))
												std::cout<<"Incorrect id book\n";
										}
										while(!(atoi(cash_id_book)>100000&&atoi(cash_id_book)<999999));
										int id_book=atoi(cash_id_book);
										national_bibli.user.OutBook(id_book,id);
										break;
									}
								case 9:
									{
										finish_user=1;
										break;
									}
								default:
									{
										std::cout<<"Default try agan";
										break;
									}

								}
							}
							std::cout<<"Out of User menu\n";
							break;
						}
					}
				}
				else
				{
					std::cout<<"\nYou are not registered\n";
				}
				break;
			}
		case 4:
			{
				std::cout<<"What id user serching?";
				char id_serching[BUF];
				do
				{
					std::cin>>id_serching;
					if(!(atoi(id_serching)>0&&atoi(id_serching)<99999))
					std::cout<<"incorrect request, try agan"<<std::endl;
				}
				while(!(atoi(id_serching)>0&&atoi(id_serching)<99999));
				int id=atoi(id_serching);
				national_bibli.User_Serch(id);
				break;
			}
		case 5:
			{
				char cash_book_id[BUF];
				do
				{
					std::cin>>cash_book_id;
					if(!(atoi(cash_book_id)>=10000&&atoi(cash_book_id)<=999999))
					std::cout<<"incorrect request,range id >100 000 and <999 999 \ntry agan"<<std::endl;
				}
				while(!(atoi(cash_book_id)>=10000&&atoi(cash_book_id)<=999999));
				int book=atoi(cash_book_id);
				BOOK::show_about_book(book);
				break;
			}
		case 9:
			{
				finish=1;
				break;
			}
		default:
			{
				std::cout<<"default\n";
				break;
			}
		}
	}
	std::cout<<"exit program\n";
	std::cin.get();
}