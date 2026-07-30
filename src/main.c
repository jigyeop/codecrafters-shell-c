#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prompt();

int main(int argc, char *argv[]) {
  setbuf(stdout, NULL);

  prompt();

  return 0;
}

void prompt() {
	char *command = NULL;
	size_t size = 0;
	printf("$ ");
	getline(&command, &size, stdin);
	printf("%s: command  not found\n", command);
	free(command);

}

