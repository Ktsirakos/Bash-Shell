#include <unistd.h>
#include <stdio.h>
#include <string.h>

void getPrompt(char* buffer){
  char prompt[300];
  char data[100];
  strcpy(prompt , getlogin());
  strcpy(data , "@cs345sh/");
  strcat(prompt , data);
  getcwd(data, sizeof(data));
  strcat(data, "/$ ");
  strcat(prompt , data);

  strcpy(buffer , prompt);

}

int main(){

  char prompt[300];
  char data[20];
  getPrompt(prompt);

  while(1){
  printf("%s" , prompt);
  printf("You want to execute %s\n" , data);
  }

}
