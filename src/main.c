#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);
	
  char comman[100];

  printf("$ ");
  scanf("%s", command);
  getchar();
  printf("{%s}: %s not found", command, command);

  return 0;
}
