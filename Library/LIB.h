#include"USER.h"
#include"ADMIN.h"
#define NAMELENGTH 20
//int const MAX_ID=9999;//maximum number of users
class LIB
{
public:
	LIB();
	~LIB();
	static void ShowCatalog();//Catalog.txt
	static void User_Serch(int);//1- 99 999
	USER user;
	ADMIN admin;
private:
	static int count_client;
};