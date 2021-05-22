#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int lengthOfTheFuckingString(char *s) {
    int length =0;
    for(int i=0; s[i]; i++) {
        length++;
    }
    
    return length;
    
}

int indexExists(char *s, char t, int length) {
    for(int i =0; i<length; i++) {
        if(s[i]==t) {
            return i;
        }
    }
    
    return -1;
}
int lengthOfLongestSubstring(char* s) {
  int length = lengthOfTheFuckingString(s);
    
  char *temp = (malloc(sizeof(char*)*length));
  memset(temp,0,length);
  int tempLength = 0;
  int maxTempLength = 0;
  int realIndex=0;

  
  for(int j=0; j<length; j++) {
      if(indexExists(temp,s[j],tempLength)>=0) {
          realIndex+=indexExists(temp,s[j],length)+1;
          memset(temp,0,tempLength);
          if(tempLength>maxTempLength) {
              maxTempLength=tempLength;
              
              
          }
 
          tempLength=0;
          temp[tempLength++]=s[realIndex];
        
          j=realIndex;
          
          if(maxTempLength>=length-j+1) {
                  return maxTempLength;
              }
      }
      else {
       
        temp[tempLength]=s[j];
        tempLength++;
      }
        
      
  }

    if(tempLength>maxTempLength) {
              maxTempLength=tempLength;
          }
    free(temp);
    return maxTempLength;
}