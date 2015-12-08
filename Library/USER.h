#include"CLIENT.h"

class USER:protected CLIENT
{
public:
	USER::USER(){};
	void ShowAboutUserAll(int id_user);
	void GetBook(int id_book,int ID_USER);
	static void AddUser(int);
	static void AddUser();
	static bool HaveUser(int);//yes or no user on database
	void OutBook(int book,int user);
private:
	int ID_USER;
};