#include "resistor_color.h"

int color_code(resistor_band_t r){
  return r;
}

resistor_band_t* colors(){
  static resistor_band_t array[10];
  for(resistor_band_t i = BLACK; i<=WHITE; i++){
    array[i] = i;
  }
  return array;
}
