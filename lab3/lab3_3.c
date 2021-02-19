#include <stdio.h>
#include <ctype.h>

/*
defect: need to throw error msg for atoi inputs containing letters
*/

int atoi(char *str);


int main(void)
{
    int i = atoi("-90");
    int i = atoi("90");
    int i = atoi("a90");

    printf("%d\n", i);
    
    return 0;
}

int atoi(char *str){
    int res=0;
    int multiplier = 1;
    
    if (*str == '-')
    {
        multiplier = -1;
        str++;
    }

    while (*str)
    {
        res *= 10;
        res += *str - '0';

        str++;
    }
    return(res * multiplier);
}
