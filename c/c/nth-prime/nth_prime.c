#include "nth_prime.h"
#include <stdint.h>
#include <stdbool.h>
bool is_prime(uint32_t n);
bool is_prime(uint32_t n){
  for(uint32_t i = 2; i<= n/2; i++){
    if(n%i==0)
    return false;
  }
  return true;
}

uint32_t nth(uint32_t n){
  uint32_t prime_num = 0;
  uint32_t num = 2;
  while(n > 0){
    if(is_prime(num)){
      n--;
      prime_num = num;
    }
    num++;
  }
  return prime_num;
}
