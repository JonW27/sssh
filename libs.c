#include <string.h>
int specialCase(char * arg, char * arg2){
  int ret;
  if(arg == NULL){
    return 0;
  }
  if(strncmp(arg, "cd", sizeof(*arg)) == 0){
    ret = 1;
  }
  else if(strncmp(arg, "exit", sizeof(*arg)) == 0){
    ret = 2;
  }
  else if(strncmp(arg, "setngs", sizeof(*arg)) == 0){
    ret = 3;
  }
  else if(arg2 == NULL){
    return 0;
  }
  if(strncmp(arg, "man", sizeof(*arg)) == 0 && strncmp(arg2, "sssh", sizeof(*arg2)) == 0){
    ret = 4;
  }
  return ret;
}
