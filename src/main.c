#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);
  
  char command[100];
  const char *builtins[] = {"echo", "exit", "type"};
  int size = sizeof(builtins) / sizeof(builtins[0]);

  while(1) {

	printf("$ ");
	scanf("%s", command);
	getchar();

	if (!(strcmp(command, "type"))) {
		scanf("%s", command);
		getchar();
		for (int i = 0; i < size; i++) {
			if (!(strcmp(command, builtins[i]))) {
				printf("%s is a shell builtin\n", builtins[i]);
				break;
			}
		}
	}
	
	else {
		printf("%s: not found\n", command);
	}	

	if (!(strcmp(command, "exit"))) {
		break;	
	}

	else if (!(strcmp(command, "echo"))) {
		int c;
		while((c = getchar()) != '\n' && c !=  EOF) {
			putchar(c);
		}
		printf("\n");
	}

	else {
		printf("%s: command not found\n", command);
  	}
  }

  return 0;
}
