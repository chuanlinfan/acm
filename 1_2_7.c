#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define STR_LEN 1000

void str2int(char c, int *value)
{
        switch (c)
        {
                case 'A':
                        *value = 4;
                        break;
                case 'B':
                        *value = 3;
                        break;
                case 'C':
                        *value = 2;
                        break;
                case 'D':
                        *value = 1;
                        break;
                case 'F':
                        *value = 0;
                        break;
                default:
                        *value = -1;
                        break;
        }
}

int main()
{
        float sum = .00;
        char str_gpa[STR_LEN] = {0};
        int i = 0, k = 0, value = 0, ret = 0;

        while(fgets(str_gpa, STR_LEN, stdin) != NULL)
        {
                ret = 0; k = 0; sum  = .00;
                for(i = 0; (i < strlen(str_gpa))&&(str_gpa[i] != '\n')&&(str_gpa[i] != '\0'); i++)
                {
                        if(str_gpa[i] != ' ')
                        {
                                str2int(str_gpa[i], &value);

                                if(value != -1)
                                {
                                        sum = sum + value;
                                        k++;
                                }
                                else
                                {
                                        ret = -1;
                                        break;
                                }
                        }

                }

                if(ret)
                {
                        printf("Unknown letter grade in input\n");
                }
                else
                {
                        printf("%.2f\n", sum/k);
                }
        }
}
