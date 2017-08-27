#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define ID_STR_LEN 20

void str2substr(char src[], char *dest, unsigned int start, unsigned int end)
{
	int i = 0, j = 0, len = 0;
	len = strlen(src);
	
	if((start <= end) && (end <= len))
	{
		for(i = start; i <= end; i++)
		{
			dest[j] = src[i];
			j++;
		}
	}
}

void id2provice(char *id_str, char *provice)
{
	switch(atoi(id_str))
	{
		case 33:
			strcpy(provice ,"Zhejiang");
			break;
		case 11:
			strcpy(provice, "Beijing");
			break;
		case 71:
			strcpy(provice, "Taiwan");
			break;
		case 81:
			strcpy(provice, "Hong Kong");
			break;
		case 82:
			strcpy(provice, "Macao");
			break;
		case 54:
			strcpy(provice, "Tibet");
			break;
		case 21:
			strcpy(provice, "Liaoning");
			break;
		case 31:
			strcpy(provice, "Shanghai");
			break;
	}
}

int main()
{
	int n = 0, i = 0, j =0;
	char **id_str, *provice, id_provice[ID_STR_LEN] = {0};
	char id_year[ID_STR_LEN] = {0},  id_month[ID_STR_LEN] = {0},  id_day[ID_STR_LEN] = {0};
	
	while( scanf("%d", &n) != EOF)
	{
		id_str = (char **) malloc (n * sizeof(char **));	
		getchar();
		
		i = 0;
		while(i < n)
		{
			id_str[i] = (char *) malloc (ID_STR_LEN * sizeof(char *));
			fgets(id_str[i], ID_STR_LEN, stdin);
			i++;
		}

		i = 0;
		while(i < n)
		{
			provice = (char *) malloc (ID_STR_LEN * sizeof(char *));
			
			memset(id_year, 0, ID_STR_LEN);			
			memset(id_month, 0, ID_STR_LEN);			
			memset(id_day, 0, ID_STR_LEN);			
			memset(id_provice, 0, ID_STR_LEN);			
			memset(provice, 0, ID_STR_LEN);
						
			str2substr(id_str[i], id_provice, 0, 1);
			id2provice(id_provice, provice);	
			str2substr(id_str[i], id_year, 6, 9);
			str2substr(id_str[i], id_month, 10, 11);
			str2substr(id_str[i], id_day, 12, 13);
			
			printf("He/She is from %s,and his/her birthday is on %02d,%02d,%4d based on the table.\n",\
			 provice, atoi(id_month), atoi(id_day), atoi(id_year));
			free(id_str[i]);
			free(provice);
			i++;
		}
		
		free(id_str);
	}
}
