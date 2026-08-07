#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shell();

int main(int argc, char *argv[]) {
  setbuf(stdout, NULL);

  shell();
  
  return 0;
}

int shell() {
	char *command = NULL;
	size_t size = 0;
	const char *ws = "\t\n\r\f\v";
	const char *ptr = command;
	
	while(1) {
		printf("$ ");
		getline(&command, &size, stdin);
		ptr = command;

		while(*ptr != '\0') {
			size_t spc = strcspn(ptr, ws);
			
			if (spc == strlen("exit") && strncmp(ptr, "exit", spc) == 0) {
				free(command);
				break;
			}
			
			if (spc == strlen("echo") && strncmp(ptr, "echo", spc) == 0) {
				ptr += spc;
				ptr += strspn(ptr, ws);	
				size_t arg = strcspn(ptr, "\n");
				printf("%.*s\n", (int)arg, ptr);
					
			}
			ptr += spc;
		}
	}
		free(command);
}

