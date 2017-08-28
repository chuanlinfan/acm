#include <stdio.h>
#include <malloc.h>
#include <string.h>

int main()
{
	int n = 0, i = 0, a = 0, b = 0, c = 0;
	int *result;
	
	scanf("%d", &n);
	result =  (int *)malloc(n*sizeof(int *));
		
	while(i < n)
	{
		scanf("%d%d%d", &a, &b, &c);
		
		if(a*a + b*b == c*c)
		{	
			result[i] = 1;
		}
		else if(a*a+c*c == b*b)
		{
			result[i] = 1;
		}
		else if(b*b+c*c == a*a)
		{
			result[i] = 1;
		}
		else
		{
			result[i] = 0;
		}	
		i++;
	}
	
	i = 0;
	while(i < n)
	{
		printf("Scenario #%d:\n", i+1);
		printf("%s\n", result[i]? "yes":"no");
		printf("\n");
		i++;
	}
	free(result);
}	
