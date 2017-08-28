#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

void sort(int const src[], int len, int *dest)
{
	int i = 0, j = 0, max = 0, swap = 0;
	
	memcpy(dest, src, len*sizeof(int *));

	for(i = 0; i < len; i++)
	{
		for(j = i+1; j < len; j++)
		{
			if(dest[i] > dest[j])
			{
				swap = dest[i];
				dest[i] = dest[j];
				dest[j] = swap;
				j = i+1;
			}
		}	
	}
}

int main()
{
	int n = 0, i = 0, k = 0, *hight, *hight_sort;
	char str_int[10000];
	char *pEnd;
	int sum = 0, average = 0, mini_move1 = 0, mini_move2 = 0;
	int move[10000] = {0}, j = 0;

	while(scanf("%d", &n) && 0 != n)
	{	
		getchar();
		hight =  (int *)malloc(n*sizeof(int *));

		fgets(str_int, 10000, stdin);

		pEnd = str_int;
		
		i = 0;
		while(i < n)
		{
			hight[i] = strtol(pEnd, &pEnd, 10);
			i++;
		}

		i = 0; sum = 0;
		while(i < n)
		{
			sum  = sum + hight[i];
			i++;
		}

		while(i > 0)
		{
			mini_move1 = 0, mini_move2 = 0;
	
			if(sum%i == 0)
			{
				average = sum/i;

				hight_sort =  (int *)malloc(n*sizeof(int *));
				sort(hight, n, hight_sort);

				k = 0;
				while(k < n)
				{
					if(k < (n-i))
					{
						mini_move1 = mini_move1 + hight_sort[k];	
					}
					else
					{
						if(hight_sort[k] > average)
						{
							mini_move2 = mini_move2 + (hight_sort[k] - average);
						}
					}		
					k++;
				}
				move[j] = mini_move1 + mini_move2;
				j++;
				printf("average = %d, i = %d, mini_move = %d\n", average, i, mini_move1 + mini_move2);
				break;
			}
			i--;
		}	
		free(hight);
		free(hight_sort);
	}
	
	for(i = 0; i < j; i++)
	{
		printf("Set #%d\n", i+1);
		printf("The minimum number of moves is %d.\n", move[i]);
		printf("\n");
	}
}
