#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  // Flush after every printf
  setbuf(stdout, NULL);

  // Uncomment this block to pass the first stage
  printf("$ ");

  // Wait for user input
  char input[100];
  char * cmd;
  char * arg;

  while (1){
    fgets(input, 100, stdin);

    input[strlen(input) - 1] = '\0';
    cmd = strtok(input, " ");
    if (strcmp(cmd, "exit") == 0){
      arg = strtok(NULL, " ");
      return atoi(arg);
    }
    else{
    printf("%s: command not found\n",input);
    printf("$ "); 
    } 
  }
  return 0;
}
