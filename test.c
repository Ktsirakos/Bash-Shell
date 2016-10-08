#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(){
  char *args[] = {"ls" , "-l" , "-a" ,NULL , "-b"};
  char *command = "/bin/ls";
  execve(command , args , 0);
  perror("execv");
  printf("done\n");
}
