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

/*
 * Takes elements from list, inserts them in the new, sorted list
 * 
 * Runtime: best O(n), worst O(n²)
 * Memory: O(1)
 */
void insertionsort(int *array, size_t const len) {
    for (int i = 1; i < len; ++i) {
        int tmp = array[i];
        int j = i;
        for(; j > 0 && tmp < array[j-1]; array[j] = array[j-1], j--)
        ;
        array[j] = tmp;
    }
}

/*
 * Takes first smallest element from list, swaps it with first element
 * in the list, then looks for next smallest element from remaining list,
 * swaps it with second element in the list ..
 * 
 * Runtime: best O(n²), worst O(n²)
 * Memory: O(1)
 */
void selectionsort(int *array, size_t const len) {
    for (int i = 0; i < len; i++) {
        int min = i;
        for (int j = i+1; j < len; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        int tmp = array[min];
        array[min] = array[i];
        array[i] = tmp;
    }
}