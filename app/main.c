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

  char builtins[][10] = {"exit","echo","type"};
  int i, flag, len_builtins = 3;

  while (1){
    fgets(input, 100, stdin);

    input[strlen(input) - 1] = '\0';
    cmd = strtok(input, " ");
    if (strcmp(cmd, "exit") == 0){
      arg = strtok(NULL, " ");
      return atoi(arg);
    }
    else if (strcmp(cmd, "echo") == 0){
      arg = strtok(NULL, " ");
      while (arg != NULL){
        printf("%s ",arg);
        arg = strtok(NULL, " ");
      }
      printf("\n");
    }
    else if (strcmp(cmd, "type") == 0){
      flag = 0;
      arg = strtok(NULL, " ");
      for (i = 0; i < len_builtins; i++)
      {
        if (strcmp(builtins[i], arg) == 0){
          printf("%s is a shell builtin\n",arg);
          flag = 1;
          break;
        }
      }
      if (flag == 0){
        printf("%s: not found\n",arg);
      }
      
    }
    else{
      printf("%s: command not found\n",input);
    }
    printf("$ "); 
  }
  return 0;
}
