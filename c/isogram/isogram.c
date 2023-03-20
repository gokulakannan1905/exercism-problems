#include "isogram.h"
#include <ctype.h>
#include <stdint.h>

bool is_isogram(const char phrase[]){
  if (!phrase)
    return false;
  for(uint16_t i=0; phrase[i]; i++){
    if(phrase[i] == ' ' || phrase[i] == '-')
      continue;
    else{
      for(uint16_t j=i+1; phrase[j]; j++){
        if(tolower(phrase[i]) == tolower(phrase[j]))
          return false;
      }
    }
  }
  return true;
}
