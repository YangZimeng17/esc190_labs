#include <stdio.h>
#include <ctype.h>


char *my_strcat(char *dest, char *src);
//int my_strcmp_rec(char *dest, char *src);
int my_strcmp_rec(char *, char *);
int atoi(char *str);


int main(void)
{
    //char one[50] = "This is ";
    //char two[] = "my house.";
    //my_strcat(one, two);
    //printf("%s\n", one);

    int i = atoi("1234");
    printf("%d\n", i);

    //Q2
    char *one = "This is c";
    char *two = "This is a";
    int answer;
    answer = my_strcmp_rec(one, two);
    printf("%d\n", answer);

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

    if (*dest != *src)
    {
        return (*dest - *src);
    }
    else if (*dest =='\0')
    {
        return 0;
    } 
    else
    {
        return my_strcmp_rec(++dest, ++src);
    }    

}


int atoi(char *str){
    // does not work yet
    char *ptr = str;
    int res = 0;
    int count = 1;
    while (*ptr != '\0'){
        printf("%s\n", *ptr);
        if (isdigit(*ptr)){
            res = (*ptr-'0')*count + res;
            count = count*10;
        }
        ptr++;
    }
    
    return res;
  
}
