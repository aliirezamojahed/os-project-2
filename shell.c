#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 64 

void get_input(char *in)
{
	int counter = 0;
	char buffer[BUFFER_SIZE];
	char *temp;

	printf(">>> ");
	fgets(buffer, BUFFER_SIZE, stdin);
	temp = strtok(buffer, " ");
	while (temp != NULL)
	{
		in[counter++] = temp;
		temp = strtok(NULL, " ");		
	}
	in[2] = NULL;
}

int main()
{
	char *args[3];
	pid_t pid;
	
	get_input(*args);

	while (1) 
	{
		pid = fork();	
		if (pid < 0)
		{
			// failure 
			printf("error!");
		} 
		else if (pid == 0)
		{
			// pid process
			execvp(args[0], args);
		}
	       	else if (pid > 0)
		{
			// parent process
			wait(NULL);
		}	
	}
	return 0;
}
