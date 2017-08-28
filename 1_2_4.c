#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define STRING_LEN 256

int char2int(char c)
{
        int value = 0;

        if(c == ' ')
        {
                value = 0;
        }
        else
        {
                value = c - 'A' + 1;
        }
        return value;
}

int main()
{
        char str_temp[STRING_LEN] = {0};
        int sum_list[STRING_LEN] = {0};
        unsigned int i = 0, j = 0, len = 0;

        i = 0;
        while(fgets(str_temp, STRING_LEN, stdin) && str_temp[0] != '#')
        {
                len = strlen(str_temp);
                j = 0;
                while(j < len && str_temp[j] != '\n' && str_temp[j] != '\0')
                {
                        sum_list[i] = sum_list[i] + (j+1)*char2int(str_temp[j]);
                        j++;
                }
                i++;
        }

        i = 0;
        while(sum_list[i] != 0)
        {
                printf("%d\n", sum_list[i]);
                i++;
        }

        return 0;
}
