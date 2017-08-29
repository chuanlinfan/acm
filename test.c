#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define VALUE_LEN 2
#define TEST_CASE 1010*1010

void sort_arry(unsigned int **dest, double *rate, unsigned int len)
{
        unsigned int *temp, i = 0, j = 0;
	double temp_rate = .00;

        temp = (unsigned int *) malloc (VALUE_LEN * sizeof(unsigned int *));
        for(i = 0; i < len; i++)
        {
                for (j = i + 1; j < len; j++)
                {
                        if(rate[i] < rate[j])
                        {
				temp_rate = rate[j];
				rate[j] = rate[i];
				rate[i] = temp_rate;

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
        int M = 0, N = 0;
        unsigned int **value, **value_sort,  temp[VALUE_LEN] = {0};
        unsigned int i = 0, j = 0, k = 0, m = 0;
        float sum = .000;
	double *rate;

        value = (unsigned int **) malloc (TEST_CASE * sizeof(unsigned int **));
        rate = (double *) malloc (TEST_CASE * sizeof(double *));
        while((scanf("%d%d", &M, &N) != EOF) && (-1 != M && -1 != N))
        {
                value[i] = (int *) malloc (VALUE_LEN * sizeof(int *));
                value[i][0] = M;
                value[i][1] = N;
		rate[i] = 1.0*value[i][0]/value[i][1];
                i++;
                m++;
        }

        i = 0;
        while(i < m && (-1 != value[i][0] && -1 != value[i][1]))
        {
                M = value[i][0];
                N = value[i][1];

                j = 0;
                value_sort = (unsigned int **) malloc (N * sizeof(unsigned int **));
                while(j < N)
                {
                        i++;
                        value_sort[j] = (int *) malloc (VALUE_LEN * sizeof(int *));
                        value_sort[j][0] = value[i][0];
                        value_sort[j][1] = value[i][1];
                        j++;
                }
                i++;

                sort_arry(value_sort, rate, N);

                k = 0; sum = .00;
                while(k < N)
                {
                        if(M >= value_sort[k][1])
                        {
                                sum = sum + value_sort[k][0];
                                M = M - value_sort[k][1];
                        }
                        else
                        {
                                sum = sum + 1.000*(M*value_sort[k][0])/value_sort[k][1];
                                M = 0;
                                break;
                        }
                        k++;
                }
                printf("%.3f\n", sum);

                j = 0;
                while(j < N)
                {
                        free(value_sort[j]);
                        j++;
                }
                free(value_sort);
		free(rate);
        }

        i = 0;
        while(i < m)
        {
                free(value[i]);
                i++;
        }
        free(value);

        return 0;
}
