#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sighandler(int signo){
  if(signo == SIGINT){
    printf("\x1b[0m \n");
    exit(0);
  }
}
