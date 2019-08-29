#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header/sort.h"

void test_bubblesort();
void print_list(int *arr,size_t const len);

int main(){
    int arr[15] = {5,1,8,3,191,9,14,62,444,79,16,88,13,55,81};
    size_t len = sizeof(arr) / sizeof(int);
    printf("--- list ---\n");
    print_list(arr, len);
    /*
     * bubble sort
     */
    printf("--- bubble sort ---\n");
    test_bubblesort(arr, len);
}

void test_bubblesort(int arr[15], size_t const len){
    int arr_cpy[len];
    memcpy(arr_cpy, arr, sizeof(arr_cpy));
    bubblesort(arr_cpy, len);
    print_list(arr_cpy, len);
}

void print_list(int *arr, size_t const len){
    for(int i=0; i<len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}