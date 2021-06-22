#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 64 

void get_input(char *in)
{
//	int counter = 0;
//	char buffer[BUFFER_SIZE];
//	char *token;
//	// passed
//	printf(">>> ");
//	fgets(buffer, BUFFER_SIZE, stdin);
//	printf("%s", buffer);
//	token = strtok(buffer, " ");
//	printf("%s\n", token);
//	for (int i = 0; token[i] != EOF; i++)
//	{
//		*in[counter][i] = token[i];
//	}
//	counter++;
//	in[counter] = token;
//	printf("%s\n", in[counter]);
	// not passed
//	token = strtok(NULL, " ");
//	printf("%s\n", token);
//	in[counter+1] = token;
//	printf("%s\n", in[counter+1]);
	
//	token = strtok(NULL, " ");		
//	while (token != NULL)
//	{
//		in[counter++] = token;
//		printf("%s\n", token);
//		token = strtok(NULL, " ");		
//	}
////	in[2] = NULL;
}

int main()
{
//	char *args[3][16];
//	= {{'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
//											{'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'},
//  										{'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'}};
	pid_t pid;
	
//	get_input(*args);
	printf(">>> ");
  char buf[BUFFER_SIZE];
	fgets(buf, BUFFER_SIZE, stdin);
  int counter = 0;
  char *p = strtok (buf, " ");
  char *args[3];

  while (p != NULL)
  {
      args[counter++] = p;
      p = strtok (NULL, " ");
  }
	args[counter] = NULL;
  for (int i = 0; i <= 2; ++i) 
      if (args[i] != NULL)
        printf("%s\n", args[i]);
//	execvp(args[0], args);
//  char *args2[] = {"ls", "-al", NULL};
//  execvp(args2[0], args2);

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
