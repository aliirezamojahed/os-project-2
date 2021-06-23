#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#define BUFFER_SIZE 64 

// Getting input from user and save into buffer
int get_input(char *str)
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
  get_input(str);
  printf("%s\n", str);
	pid_t pid;
	
//	while (1) 
//	{
//		pid = fork();	
//		if (pid < 0)
//		{
//			// failure 
//			printf("error!");
//		} 
//		else if (pid == 0)
//		{
//			// pid process
////      const command = args[0];
//			execvp(args[0], args);
//		}
//	       	else if (pid > 0)
//		{
//			// parent process
//			wait(NULL);
//		}	
//	}
	return 0;
}
