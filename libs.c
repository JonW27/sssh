#include <string.h>
int specialCase(char * arg, char * arg2){
  int ret;
  if(strncmp(arg, "cd", sizeof(*arg))){
    ret = 1;
  }
  else if(strncmp(arg, "exit", sizeof(*arg))){
    ret = 2;
  }
  else if(strncmp(arg, "setngs", sizeof(*arg))){
    ret = 3;
  }
  if(strncmp(arg, "man", sizeof(*arg)) && strncmp(arg2, "sssh", sizeof(*arg2))){
    ret = 4;
  }
  return ret;
}
