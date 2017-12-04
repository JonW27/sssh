# sssh
Supa Simple SHell

Good:

* the shell itself
* cd, exit commands
* semicolons + trailing, leading spaces
* sdebug can switch debug flag on or off
* ANSI colors!

Attempted:
* redirection

Intended to do, but never got done:
* piping (I think I could've done this, but redirection took literally several hours getting me nowhere; time constraints)
* commands.txt file (again, think I could've gotten this done)
* history
* personal man page for sssh (I'll still do this, but it'll be late)

## Screencast

[![asciicast](https://asciinema.org/a/UZFHOxkAxdQ7VLwXhtkf35xRE.png)](https://asciinema.org/a/UZFHOxkAxdQ7VLwXhtkf35xRE)

## Function headers

```C
void * prompt(); // takes nothing, returns nothing, prints prompt

char * trim_cmd(char *); // takes a char array cmd, trims it, returns char array

char ** parse_args(char *); // parses shell args, takes an individual command, and returns an array of char arrays

char ** parse_cmds(char *); // the same as above, but for cmds

void print_args(char **); // takes array of char arrays, for debug purposes, returns nothing

void print_cmds(char **); // does the same as above, but for cmds

void run_cmd(char *); // takes a char array from parse_cmds, will run it as follows, returns nothing

void sighandler(int); // takes a sig int and takes program action in response, returns nothing

int specialCase(char *, char *); // takes two char arrays, for arg 0 and arg 1, and determines if there is a special case for the commands, returns an int for the status based off this

```
