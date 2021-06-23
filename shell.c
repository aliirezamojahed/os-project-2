#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#define BUFFER_SIZE 64 

// Getting input from user and save into buffer
int getInput(char *str)
{
  char *buffer;
  buffer = readline(">>> ");
  printf("%s\n", buffer); 
  if (strlen(buffer) != 0)
  {
    add_history(buffer);
    strcpy(str, buffer);
    return 0;
  } 
  else
  {
    return 1;
  }
}

int main()
{
	char *args[3];
  char str[BUFFER_SIZE];
  getInput(str);
  printf("%s\n", str);
  
  char *token = strtok(str, " ");
  int counter = 0;
  
  while (token != NULL)
  {
    args[counter++] = token;
    token = strtok(NULL, " ");
  }
  args[2] = NULL;
  printf("%s\n%s\n", args[0], args[1]);
  
	return 0;
}
