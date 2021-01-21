#include <stdio.h>

// problem 1
void f(int *p_a){
    *p_a = 10;
}

// problem 2
void insertion_sort(int arr[], int length){
    for (int i = 1; i < length; i++){
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
}

void print_array(int arr[]){
    int i = 0;
    while(i < 6){
       printf("%d\n", arr[i]);
       i++;
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
    int size = sizeof arr / sizeof arr[0];
    insertion_sort(arr, size);

    print_array(arr);
    return 0;
}