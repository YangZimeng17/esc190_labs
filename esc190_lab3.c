#include <stdio.h>

char *my_strcat(char *dest, char *src);
int my_strcmp_rec(char *dest, char *src);

int main(void)
{
    char one[50] = "This is ";
    char two[] = "my house.";
    my_strcat(one, two);
    printf("%s\n", one);

    return 0;
}


char *my_strcat(char *dest, char *src){
    char *ptr = dest;
    char *ptr1 = src;
    while (*ptr != '\0'){
        ptr++;
    }
    while (*ptr1 != '\0'){
        *ptr = *ptr1;
        ptr++;
        ptr1++;
    }
    *ptr1 = '\0';

    return dest;
}


int my_strcmp_rec(char *dest, char *src){

    
}
