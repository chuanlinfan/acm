#include "DATList.h"

INT DATList::InitList()
{
	m_List = new (intList);
	
	m_List->item = 5;
	m_List->next = NULL;
	
	m_Len = 1;
	
	return 0;
}

INT DATList::InsertList(int value, int position)
{
	if(position <= m_Len)
	{
		int i = 0;
		intList *temp, *swap;
		intList *tlist  = new (intList);

		tlist->item  =  value;
		tlist->next = NULL;
		
		temp = m_List;
		while(temp)
		{
			if(position == i)
			{
				swap = temp->next;
				temp->next = tlist;
				temp->next->next = swap;
				m_Len++;
				break;
			}
			temp = temp->next;
			i++;
		}
	}
	return 0;
}

INT DATList::DelList(int position)
{
	int i = 1;
	intList *temp;
	
	temp = m_List;
	while(temp->next)
	{
		if(position == i)
		{
			temp-> next = temp -> next ->next;
			break;
		}
		temp = temp->next;
		i++;
	}
	return 0;
}

INT DATList::GetItem(int position)
{
	intList *temp;
	
	temp = m_List;
	while(temp)
	{
		cout<<temp->item<<endl;
		temp = temp->next;
	}
	
	return 0;
}

