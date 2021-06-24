#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#define BUFFER_SIZE 64 
#define ARGS_SIZE 16

// Getting input from user and save into buffer
int getInput(char *str)
{
  char *buffer;
  buffer = readline(">>> ");
  printf("buffer: %s\n", buffer); 
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
	char *args[ARGS_SIZE];
  char str[BUFFER_SIZE];
  getInput(str);
  printf("str: %s\n", str);
  
  char *token = strtok(str, " ");
  int counter = 0;
  
  while (token != NULL)
  {
    args[counter++] = token;
    token = strtok(NULL, " ");
  }
  args[counter] = NULL;
  for (int i = 0; i < counter; i++)
  {
    printf("param %d: %s\n", i, args[i]);
  }
  
	return 0;
}
