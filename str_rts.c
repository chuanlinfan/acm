#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAX_STR_LEN 1000

int main()
{
	unsigned int count = 0, k = 0;
	int start = 0, end = 0, i = 0, j = 0, len = 0;
	
	char *src;
	char *dest[MAX_STR_LEN];
		
	scanf("%d",&count);
	getchar();
	
	*dest = malloc(count);

	while(k < count)
	{
		len = 0;
		src = malloc(MAX_STR_LEN*sizeof(char));
		dest[k] = malloc(MAX_STR_LEN*sizeof(char));

		memset(src,0,sizeof(src));
		memset(dest[k],0,sizeof(*dest[k]));

		fgets(src, MAX_STR_LEN, stdin);
		len = strlen(src);

		start = 0, end = 0;
		for(i = 0; i < len; i++)
		{
			end = i;
			if(src[end] == ' ' || src[end] == '\n')
			{
				for(j = start; j < end; j++)
				{
					dest[k][j] = src[end - 1 - j + start];
				}
				if(src[end] == ' ')
				{
					dest[k][j] = ' ';
				}
				else
				{
				//	*dest[k][j] = '\n';
				}
				start = end + 1;
			}
		}
		free(src);
		k++;
	}	
	k = 0;
	while(k < count)
	{
		puts(dest[k]);
		k++;
	}
	k = 0;
	while(k < count)
	{
		free(dest[k]);
		k++;
	}
}
