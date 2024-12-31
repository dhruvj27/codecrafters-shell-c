#include <stdio.h>
#include <string.h>

int main() {
  // Flush after every printf
  setbuf(stdout, NULL);

  // Uncomment this block to pass the first stage
  printf("$ ");

  // Wait for user input
  char input[100];

  while (1){
    fgets(input, 100, stdin);

    input[strlen(input) - 1] = '\0';
    if (strcmp(input, "exit") == 0){
      break;
    }
    else{
    printf("%s: command not found\n",input);
    printf("$ "); 
    } 
  }
  return 0;
}
