#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);
	
  char command[100];

  printf("$ ");
  scanf("%s", command);
  getchar();
  printf("%s: command not found", command);

  return 0;
}
