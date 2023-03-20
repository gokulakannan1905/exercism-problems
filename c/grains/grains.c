#include "grains.h"
#include <math.h>
#include <stdint.h>

uint64_t square(uint8_t n){
  if(n>=1 && n<=64)
    return (uint64_t)pow(2,n-1);
  return 0;
}

uint64_t total(){
  uint64_t total = 0;
  for(uint8_t i = 1; i<65;i++){
    total += square(i);
  }
  return total;
}
