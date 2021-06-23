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

void hello() {
	printf("Hello, Welcome, nice to meet you!\n");
	// another features...
}

int changeDirectory(char *path) {
	// char s[100];

	// printing current working directory
    // printf("%s\n", getcwd(s, 100));
	if (chdir(path) != 0) {
		perror("chdir() is failed!");
	}
	// printing current working directory
    // printf("%s\n", getcwd(s, 100));

	return 0;
}

int main() {
	
	while (1) {
		
		char *args[3] = {"byeShell", "..", "NULL"};
		pid_t pid;
		// get_input(*args);
		
		if (args[0] != "byeShell") {
			if (args[0] == "helloShell") {
				hello();
				// break; // for debug
			} else if ( args[0] == "cd") {
				// cd os992 : args[0] = cd, args[1] = path (e.g, os992)
				changeDirectory(args[1]); // passing path to the function
				// break; // for debug
			} else {
				// TODO e,g. fork
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
		} else {
			// exit from loop
			printf("See you later! bye...\n");
			break;
		}
	}	
	
	return 0;
}
