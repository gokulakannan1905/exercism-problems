#include "binary_search.h"
#include<stdio.h>
const int* binary_search(int value, const int *arr, size_t length){
    if(length == 0) return NULL;
    size_t middle_index = length/2;
    if(arr[middle_index] == value) return &arr[middle_index];    
    else if(value < arr[middle_index]) return binary_search(value,arr,middle_index);    
    else return binary_search(value,&arr[middle_index+1],length - (middle_index+1));
}
