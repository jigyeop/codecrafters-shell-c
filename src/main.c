#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int shell();

int main(int argc, char *argv[]) {
  setbuf(stdout, NULL);

  shell();
  
  return 0;
}

int shell() {
	const char *builtins[] = {"exit", "echo", "type"};
	const size_t num_builtins = sizeof(builtins) / sizeof(builtins[0]);
	char *command = NULL;
	size_t size = 0;
	const char *ws = " \t\n\r\f\v";
	const char *ptr;
	
	while(1) {
		printf("$ ");
		getline(&command, &size, stdin);
		ptr = command;

		while(*ptr != '\0') {
			size_t spc = strcspn(ptr, ws);

			if (strncmp(ptr, "type", spc) == 0 && "type"[spc] == '\0') {
				ptr += spc;
				ptr += strcspn(ptr, ws);

				for (int i = 0; i < num_builtins; i++) {
					if (strcmp(ptr, builtins[i]) == 0) {
						printf("%.*s is a builtin", (int)spc,  ptr);
					}
				}
			}

			
			if (strncmp(ptr, "exit", spc) == 0 && "exit"[spc] == '\0') {
				free(command);
				return 1;
			}
			
			if (strncmp(ptr, "echo", spc) == 0 && "echo"[spc] == '\0') {
				ptr += spc;
				ptr += strcspn(ptr, ws);	
				size_t arg = strcspn(ptr, "\n");
				printf("%.*s\n", (int)arg, ptr);
				break;
			}

			if (spc > 0) {
				printf("%.*s: command not found\n", (int)spc, ptr);
				break;
			}
			ptr += spc;
			ptr += strspn(ptr, ws);
		}
	}
		free(command);
}

