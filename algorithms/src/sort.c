#include "../header/sort.h"


/*
 * Double loops over list, compares adjacent elements and swaps them
 * 
 * Runtime: best O(n), worst O(n²)
 * Memory: O(1)
 */
void bubblesort(int *array, size_t const len){
    int tmp;
    for (int i = 1; i < len ; i++) {
        for (int j = 0; j < len - i ; j++) {
            if (array[j] > array[j+1]) {
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
}