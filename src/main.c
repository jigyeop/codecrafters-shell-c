#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);
  
  char command[100];

  while(1) {

	printf("$ ");
	scanf("%s", command);
	getchar();

	if (!(strcmp(command, "exit"))) {
		break;	
	}

	else if (!(strcmp(command, "echo"))) {
		int c;
		while((c = getchar()) != EOF) {
			putchar(c);
		}
		printf("\n");
	}

	else {
		printf("%s is an unknown command.\n", command);
  	}
  }

  return 0;
}
