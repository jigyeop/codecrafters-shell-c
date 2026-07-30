#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prompt();

int main(int argc, char *argv[]) {
  setbuf(stdout, NULL);

  while(1) {
	  if (!prompt()) {
		  break;
	  }
  }
  
  return 0;
}

void prompt() {
	char *command = NULL;
	size_t size = 0;
	
	printf("$ ");

	getline(&command, &size, stdin);
	command[strcspn(command, "\n")] = '\0';

	if (!strcmp("exit", command)) {
		free(command);
		return 0;
	}

	printf("%s: command not found\n", command);
	
	free(command);
	return 1;
}

