#include "DATList.h"

int main()
{
	DATList *list = new (DATList);
	
	list->InitList();
	list->InsertList(2,0);
	list->InsertList(3,0);
	list->InsertList(4,0);
	list->InsertList(5,0);
	list->GetItem(0);
	list->DelList(2);
	cout<< endl;
	list->GetItem(0);
	cout<< endl;
	list->DelList(3);
	list->DelList(2);
	list->GetItem(0);
	
	return 0;
}
