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

void read_command(char* command , char parameters[10][10] , int *number){
  int i = 0;
  int j = 0;
  int first_argument = 0;
  char *pch;
  char data[50];
  fgets(data , sizeof(data) , stdin);

  /* Code for splitting input */
    pch = strtok (data," \n");
    while (pch != NULL)
    {
      if(first_argument == 0) {
        //strcat(command , "/bin/");
        strcpy(command , pch);
        first_argument = 1;
      }else{
      strcpy(parameters[i] , pch);
      i++;
      *number = *number + 1;
    }
    pch = strtok (NULL, " \n");
    }

  if(i > 0){
    do{
      printf("%s\n" , parameters[j]);
      j++;
    }while(j < i);
  }
}

int main(){
/*---------------------------*/
  char prompt[300];
  char data[20];
  char command[30];
  char parameters[10][10];
  int status , i;
  int numberofparameters = 0;
/*-----------------------------*/
  getPrompt(prompt);

  while(1){
  printf("%s" , prompt);
  read_command(command , parameters , &numberofparameters);

  printf("You want to execute %s" , command);

  for(i = 0; i < numberofparameters; i++){
    printf(" %s " , parameters[i]);
  }

  printf("\n");

  pid_t pid = fork();
  if(pid == 0){
    execve(command , parameters , 0);
    strcpy(command , "");
    for(i = 0; i < numberofparameters; i++){
      strcpy(parameters[i] , "");
    }
  }else{
      waitpid(-1, &status, 0);
    }
  }
}
