#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prompt(); 

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);
	

  prompt();

  fgets(command, sizeof(command), stdin);
  command[strcspn(command, "\n")] = '\0';
  printf("%s : command not found", command);

  return 0;
}

void prompt() {
	printf("$ ");
}
