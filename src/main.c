#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);
  
  char command[100];
  const char *builtins[] = {"echo", "exit", "type"};
  char *path = getenv("PATH");
  int size = sizeof(builtins) / sizeof(builtins[0]);

  while(1) {

	printf("$ ");
	scanf("%s", command);
	getchar();

	if (!(strcmp(command, "type"))) {
		scanf("%s", command);
		getchar();
		int flag = 0;
		char *dir = strtok(path, ":");
		strcat(dir, "/");
		while(dir != NULL) {
			if (access(strcat(dir, command), F_OK) == 0) {
				if (access(strcat(dir, command), X_OK) == 0) {
					printf("%s is %s", command, dir);
					flag = 1;
					break;
				}
			}
			dir = strtok(NULL, ":");
		}
		
		if (flag != 1) {
			printf("%s: not found");
			break;
		}

	}
			

	else if (!(strcmp(command, "exit"))) {
		break;
	}

	else if (!(strcmp(command, "echo"))) {
		int c;
		while((c = getchar()) != '\n' && c != EOF) {
			putchar(c);
		}
		printf("\n");
	}

	else if (!(strcmp(command, "type"))) {
		int flag = 0;
		scanf("%s", command);
		getchar();
		for (int i = 0; i < size; i++) {
			if (!(strcmp(command, builtins[i]))) {
				printf("%s is a shell builtin\n", builtins[i]);
				flag = 1;
			}
		}

		if (flag != 1) {
			printf("%s: not found\n", command);
		}
	}

	else {
		printf("%s: command not found\n", command);
  	}
  }

  return 0;
}
