#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);
  
  char command[128];
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

			for (int i = 0; i < size; i++) {
				if (!(strcmp(command, builtins[i]))) {
					printf("%s is a shell builtin\n", builtins[i]);
					flag = 1;
					break;
				}
			}
			if (!flag && path != NULL) {
				char *path_copy = strdup(path);
				char *dir = strtok(path_copy, ":");
			
				while(dir != NULL) {
					char full_path[1024];
					snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
					
					if (access(full_path, F_OK | X_OK) == 0) {
						printf("%s is %s\n", command, full_path);
						flag = 1;
						break;
					}
					dir = strtok(NULL, ":");
				}
			}
			if (flag != 1) {
				printf("%s: not found\n", command);
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

	else {
		printf("%s: command not found\n", command);
  	}
	}
}

  return 0;
}
