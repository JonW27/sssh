#include <string.h>
int specialCase(char * arg, char * arg2){
  int ret;
  if(arg == NULL){
    return 0;
  }
  else if(strncmp(arg, "cd", 3) == 0){
    ret = 1;
  }
  else if(strncmp(arg, "exit", 5) == 0){
    ret = 2;
  }
  else if(strncmp(arg, "setngs", 7) == 0){
    ret = 3;
  }
  else if(strncmp(arg, "sdebug", 7) == 0){
    ret = 5;
  }
  else if(arg2 == NULL){
    return 0;
  }
  else if(strncmp(arg, "man", 4) == 0 && strncmp(arg2, "sssh", 5) == 0){
    ret = 4;
  }
  else{
    ret = 0; // for reg cmds
  }
  return ret;
}
