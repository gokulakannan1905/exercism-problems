#include "perfect_numbers.h"
#include<stdio.h>
kind classify_number(int n){
    if(n<=0){
        return ERROR;
    }
    int aliquot_sum = 1;
    for(int i=2;i<=n/2;i++){
        if(n%i==0){
            aliquot_sum+=i;
        }
    }
    if(aliquot_sum == n && n!=1){
        return PERFECT_NUMBER;
    }else if(aliquot_sum > n){
        return ABUNDANT_NUMBER;
    }else{
        return DEFICIENT_NUMBER;
    }
}