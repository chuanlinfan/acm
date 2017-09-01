#ifndef __DATLIST_H__
#define __DATLIST_H__

#include "base.h"

typedef struct list
{
        int item;
        list *next;
}intList;

class DATList
{
        public:
                INT InitList();
		INT GetLen();
                INT InsertList(int value, int position=0);
                INT DelList(int i);
                INT GetItem(int i);
        private:
                intList *m_List;
		int m_Len;
};

#endif

