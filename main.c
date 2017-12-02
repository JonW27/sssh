#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include "libs.h"
#include "signals.h"

void prompt(){
  printf("\e[1;95m$ \e[1;94msssh\e[0;106m\e[0m\e[1;91m> ");
}

char ** parse_args(char line[]){
  char ** args;
  args = malloc(100); // support 100 args
  int i = 0;
  char * element;
  element = malloc(100); // support 100 args
  while((element = strsep(&line, " ")) != NULL){
    args[i] = element;
    i++;
  }
  args[i] = NULL;
  return args;
}

char ** parse_cmds(char line[]){
  char ** args;
  args = malloc(100); // support 100 args
  int i = 0;
  char * element;
  element = malloc(100); // support 100 args
  while((element = strsep(&line, ";")) != NULL){
    args[i] = element;
    i++;
  }
  args[i] = NULL;
  return args;
}
 

void print_args(char ** args){
	int i = 0;
	while(args[i]){
		printf("args[%d]: %s\n", i, args[i]);
		i++;
	}
}

void run_cmd(char * cmd){
	
}

int main(){
  signal(SIGINT, sighandler);
  char line[200]; // can change size of this later
  while(1){
    prompt();
    fgets(line, 200, stdin);
    line[strcspn(line, "\n")] = 0;
    printf("\x1b[0m \n");
    char ** cmds = parse_cmds(line);
    // inlude separate command, runcmd
    char ** args = parse_args(line);
    print_args(args);
    int class = specialCase(args[0], args[1]); // cd, exit, my shell man page
    printf("class: %d\n", class);
    int status;
    if(1){//!class){
      int f = fork();
      if(f == 0){
	printf("forked\n");
        execvp(args[0], args);
      }
      else{
        int no_err = wait(&status);
        //printf("child status: %d", WEXITSTATUS(status));
	//printf("parent finished");
      }
    }
    else{
      if(class == 1){
        // cd
        printf("cd\n");
      }
      else if(class == 2){
        // exit
      }
      else if(class == 3){
        // setngs
      }
      else{
        // man sssh
      }
    }
  }

  return 0;
}
