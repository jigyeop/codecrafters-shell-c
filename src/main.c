#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prompt();
void allocate();

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  prompt();
  allocate();

  return 0;
}

void prompt() {
	printf("$ ");
}

void allocate() {
	char *command = NULL;
	size_t size = 0;
	getline(&command, &size, stdin);
	free(command);
}

