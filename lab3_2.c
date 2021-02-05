#include <stdio.h>
#include <ctype.h>
/*
   Write a recursive version of strcmp. The signature must be
   int my_strcmp_rec(char *str1, char *str2).
   The function should return 0 if the contents of str1 and str2
   are the same.
   If the contents of str1 and str2 are not the same, and the first
   character that doesn't match is at location i, the function
   should return str1[i]-str2[i].
   Each character corresponds to an integer value. For example,
   'A' corresponds to 65, 'B' corresponds to 66, ..., 'Z' 
   corresponds to 90, 'a' corresponds to 97, 'b' corresponds to
   98, ... 
   https://simple.wikipedia.org/wiki/ASCII#/media/File:ASCII-Table-wide.svg
   Returning the difference between the first pair of unmatched characters
   makes it so that strcmp returns a negative value if str1 comes before
   str2 in a lexicographic order.
*/


char *slicing(char *str, int len){
    /*
    int len = 0;
    while(*str != '\0'){
        len++;  //len = len + 1
        str++;
    }
    */

    char res[len-1];

    for (int i=1; i<len; i++){
        res[i] = str[i];
    }

    return res;
}


int my_strcmp_rec(char *str1, char *str2){
    if (str1[0] != str2[0]){
        return (str1[0]-str2[0]); 
    }

    else{
        int len1 = 0;
        while(*str1 != '\0'){
            len1++;  //len = len + 1
            str1++;
        }

        int len2 = 0;
        while(*str2 != '\0'){
            len2++;  //len = len + 1
            str2++;
        }

        return my_strcmp_rec(slicing(str1, len1), slicing(str2, len2));
    }

}


int main(void)
{

    char *one = "This is c";
        /*
    char *two = "This is a";
    int answer;
    answer = my_strcmp_rec(one, two);
    printf("%d\n", answer);
    */

    printf("%s", slicing(one, 9));
    return 0;
}