#include <stdio.h>
#include <string.h>
#include <malloc.h>

void char_reverse(char src[], char *dest)
{
	unsigned int i = 0, j = 0, len = 0;
	
	len = strlen(src);
	printf("%d\n",len);
	j = 0;
	
	for(i = len - 1; i > 0; i--)
	{	
		if(src[i] != '\0')
		{
			dest[j] = src[i];
			j++;
		}
	}	

	dest[j] = src[0];
	if(j < len - 1)
	{
		dest[len-1] = '\0';
	}
}

int main()
{
	char *src;
	char *dest;
	char *token;
	char *token_reverse;
	char *splitchar = " ";
	char split = ' ';
	unsigned int i = 0;
	
	src = malloc(1001*sizeof(char));
	dest = malloc(1001*sizeof(char));
	token_reverse = malloc(1001*sizeof(char));

	fgets(src, 1000, stdin);
	
	for(int i = 0;; i ++)
	{
		token = strtok(src, splitchar);
		if (token == NULL)
		{
			break;
		}
		char_reverse(token, token_reverse);
		strcat(dest, token_reverse);
		if (src != NULL) 
		{
			src = NULL; // 对src置空
		}
	}
	printf("%d\n", (int)strlen(dest));
	puts(dest);

	free(src);
	free(dest);
	free(token_reverse);
}
