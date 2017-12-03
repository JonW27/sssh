#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <ctype.h>

#include "libs.h"
#include "signals.h"

bool DEBUG = true;

char * trim_cmd(char *);

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
    args[i] = trim_cmd(element);
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

void print_cmds(char ** cmds){
	int i = 0;
	while(cmds[i]){
		printf("cmds[%d]: %s\n", i, cmds[i]);
		i++;
	}
}

char * trim_cmd(char * elem){
  // theres no standard way to do this, I consulted stackoverflow
  int size = strlen(elem);

  while(isspace(*elem)){ // checks if space
    elem++;
  }

  if(elem == NULL){ // in the case that the element is just spaces
    return elem;
  }

  char * end;
  end = elem + size - 1;

  while(end>= elem && isspace(*end)){
    end--;
  }
  //*(end + 1) = 0;
  return elem;
}

void run_cmd(char * cmd){
  char ** args = parse_args(cmd);
  if(DEBUG){
      print_args(args);
  }
  int class = specialCase(args[0], args[1]); // cd, exit, my shell man page
  if(DEBUG){
      printf("class: %d\n", class);
  }
  int status;
  if(!class){
    int f = fork();
    if(f == 0){
      if(DEBUG){
          printf("forked\n");
      }
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
    else if(class == 4){
      // man sssh
    }
    else if(class == 5){
      // debug
      DEBUG = !DEBUG;
      printf("Debug flag now set to %d\n", DEBUG);
    }
    else{
      // man sssh
    }
  }
}

int main(){
  signal(SIGINT, sighandler);
  char line[200]; // can change size of this later
  while(1){
    prompt();
    fgets(line, 200, stdin);
    line[strcspn(line, "\n")] = 0;
    printf("\x1b[0m \n"); // reset char
    char ** cmds = parse_cmds(line);
    if(DEBUG){
      print_cmds(cmds);
    }
    // include separate command, runcmd
    int i = 0;
    while(cmds[i]){
      run_cmd(cmds[i]);
      i++;
    }
  }

  return 0;
}
