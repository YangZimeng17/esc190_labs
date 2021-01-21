#include <stdio.h>

// problem 1
void f(int *p_a){
    *p_a = 10;
}

// problem 2
void insertion_sort(int arr[]){
    /*
    printf("sizeof(a): %d\n", sizeof(a));
    printf("sizeof(a): %d\n", sizeof(a));
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("size: %d\n", size);
    */
    for (int i = 1; i < 6; i++){
        while(arr[i] < arr[i-1]){
            int temp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = temp;
            i--;
            if(arr[i]>= arr[i-1]){
                break;
            }
        }
    }

    // https://www.geeksforgeeks.org/insertion-sort/
    // website for insertion-sort c algorithm
}

void print_array(int arr[]){
    int i = 0;
    while(i < 5){
       printf("%d\n", arr[i]);
       i++; // same as i = i + 1
   }
}

int main(){
    // problem 1
    int a = 5;
    printf("a: %d\n", a);
    f(&a);
    printf("a: %d\n", a);

    //problem 2

    int arr[] = {12,2,31,11,5,9};
    //int a[5] = {5, 3, 7, 5, 1};
    insertion_sort(arr);
    print_array(arr);
    return 0;
}