#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define STR_LEN 1010

int main()
{
	int n = 0, i = 0, j = 0, k = 0;
	char temp_str[STR_LEN] = {0}, temp_format[STR_LEN] = {0};
	char **str_list;
	int sum_list = 0;

	while(scanf("%d", &n) != EOF)
	{
		sum_list = 0;	
		getchar();
		str_list = (char **) malloc (n*sizeof(char **));

		i = 0;
		while(i < n)
		{
			str_list[i] = malloc(STR_LEN*sizeof(char *));
			memset(str_list[i], 0, STR_LEN*sizeof(char *));

			fgets(str_list[i], STR_LEN, stdin);

			memset(temp_str,0,sizeof(temp_str));
			memset(temp_format,0,sizeof(temp_format));
			for(j = 0; j < strlen(str_list[i]); j++)
			{
				if(str_list[i][j] != '(')
				{
					temp_str[j] = str_list[i][j];
				}
				else
				{
					break;
				}			
			}

			k = 0;j++;
			for(; j < strlen(str_list[i]); j++)
			{
				if(str_list[i][j] != ')')
				{
					temp_format[k] = str_list[i][j];
				}
				else
				{
					break;
				}				
				k++;
			}

			free(str_list[i]);
			sum_list = sum_list + strtol(temp_str, NULL, atoi(temp_format));
			i++;
		}
		
		printf("%d\n", sum_list);
		free(str_list);
	}
}
