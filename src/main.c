#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int shell();

int main(int argc, char *argv[]) {
  setbuf(stdout, NULL);

  while(1) {
	  if (!shell()) {
		  break;
	  }
  }
  
  return 0;
}

int shell() {
	char *command = NULL;
	size_t size = 0;
	
	printf("$ ");

	getline(&command, &size, stdin);
	command[strcspn(command, "\x20")] = '\0';

	if (!strcmp("exit", command)) {
		free(command);
		return 0;
	}

	if (!strcmp("echo", command)) {
		printf("%s\n", command + size);
		free(command);
		return 1;
	}

	printf("%s: command not found\n", command);
	
	free(command);
	return 1;
}

