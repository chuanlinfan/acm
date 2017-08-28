#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define VALUE_LEN 2

void sort_arry(int **dest, int len)
{
	int *temp, i = 0, j = 0;
	
	temp = (int *) malloc (VALUE_LEN * sizeof(int *));
	for(i = 0; i < len; i++)
	{
		for (; j < len; j++)
		{
			if((dest[i][0]/dest[i][1]) < (dest[j][0]/dest[j][1]))
			{
				temp[0] = dest[j][0]; temp[1] = dest[j][1];
				dest[j][0] = dest[i][0]; dest[j][1] = dest[i][1];
				dest[i][0] = temp[0]; dest[i][1] = temp[1];
				j = i + 1;
			}
		}
	}	
	free(temp);
}

int main()
{
	int M = 0, N = 0, **value, temp[VALUE_LEN] = {0};
	unsigned int i = 0, j = 0;
	float sum = .00;
	
	while(scanf("%d%d", &M, &N) != EOF)
	{
		if((-1 == M) && (-1 == N))
		{
			break;
		}
		
		value = (int **) malloc (N * sizeof(int **));
		i = 0;
		while(i < N)
		{
			value[i] = (int *) malloc (VALUE_LEN * sizeof(int *));
			scanf("%d%d", &value[i][0], &value[i][1]);
			i++;
		}
				
		sort_arry(value, N);

		i = 0;
		while(i < N)
		{
			printf("%d %d\n", value[i][0], value[i][1]);
			i++;
		}

		i = 0;
		while(i < N)
		{
			if(M >= value[i][1])
			{
				sum = sum + value[i][0];
				M = M - value[i][1];
			}
			else
			{
				sum = sum + (float)(M/value[i][1])*value[i][0];
			}
			printf("%d %d\n", value[i][0], value[i][1]);
			i++;
		}
		printf("%.4f\n", sum);			
	}
	return 0;
}
