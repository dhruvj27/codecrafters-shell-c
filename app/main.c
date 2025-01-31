#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
  // Flush after every printf
  setbuf(stdout, NULL);

  // Uncomment this block to pass the first stage
  printf("$ ");

  // Wait for user input
  char input[100];
  char *cmd;
  char *arg = NULL, *folder;

  char builtins[][10] = {"exit","echo","type"};
  int i, flag, len_builtins = 3;

  DIR *d;
  struct dirent *dir;

  char * path, * path_copy = NULL, *pathdup;
  
  while (1){
    fgets(input, 100, stdin);

    int l=strlen(input);
    input[l - 1] = '\0';
    //printf("%s,",input);
    
    cmd = strtok(input, " ");
    arg = realloc(arg, l - strlen(cmd));
    strcpy(arg, input + strlen(cmd) + 1);
    //printf("%s,%s\n",cmd,arg);

    
    //path_copy = (char*)malloc(strlen(path)); 
    // printf("%s ",path);
    if (strcmp(cmd, "exit") == 0)
    {
      free(path_copy);
      i = atoi(arg);
      free(arg);
      return i;
    }
    else if (strcmp(cmd, "echo") == 0)
    {
      printf("%s\n",arg);
    }
    else if (strcmp(cmd, "type") == 0)
    {
      flag = 0;
      
      
      for (i = 0; i < len_builtins; i++)
      {
        if (strcmp(builtins[i], arg) == 0){
          printf("%s is a shell builtin\n",arg);
          flag = 1;
          break;
        }
      }

      if (flag == 1)
      {
        printf("$ ");
        continue;
      }

      path = getenv("PATH");
      pathdup = strndup(path, strlen(path));
      folder = strtok(pathdup, ":");
      int count = 0;
      do{
        d = opendir(folder);
        //if (strcmp(folder,"/usr/bin") == 0  || strcmp(folder,"/bin") == 0) printf("%s ",folder);
        if (d)
        {
          while ((dir = readdir(d)) != NULL)
          {
            if (dir->d_type == DT_REG && strcmp(dir->d_name, arg) == 0)
            {
              printf("%s is %s/%s\n",arg,folder,arg);
              flag = 1;
              break;
            }
          }
        }
        closedir(d);
        if (flag == 1) break;
      } 
      while ((folder=strtok(NULL,":"))!=NULL);
      

      if (flag == 0){
        printf("%s: not found\n",arg);
      }
      
    }
    else{
      printf("%s: command not found\n",input);
    }
    printf("$ "); 
  }
  free(arg);
  free(path_copy);
  return 0;
}
