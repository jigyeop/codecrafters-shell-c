#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);
	
  char command[100];

  while(1) {
	printf("$ ");
	scanf("%s", command);
	getchar();
	if (command == "exit") {
		break;
	}
	printf("%s: command not found\n", command);
  }

  return 0;
}
